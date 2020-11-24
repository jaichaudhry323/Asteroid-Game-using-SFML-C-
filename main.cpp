
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
//#include "Testing_Functions.h"

#define run cout<<__LINE__<<endl;
#define pb push_back
using namespace std;
using namespace sf;

float degToRad = 3.14 / 180;
int H = 1000, W = 1200;

class Animation
{
public:
  float frame, speed;
  Sprite sprite;
  vector<IntRect>frames;

  Animation() {}

  Animation(Texture &t, int x, int y, int w, int h, int count, float spd)
  {
    speed = spd;
    frame = 0;

    for (int i = 0; i < count; i++)
      frames.pb(IntRect(x + i * w, y, w, h));

    sprite.setTexture(t);
    sprite.setOrigin(w / 2, h / 2);
    sprite.setTextureRect(frames[0]);
  }

  void update()
  {
    frame += speed;
    if (frame >= frames.size()) frame -= frames.size();
    if (frames.size() > 0)sprite.setTextureRect( frames[ (int)frame ] );
  }

  int isEnd()
  {
    return frame + speed >= frames.size();
  }
};


class Entity
{
public:
  int life = 1, radius;
  int id = 0;
  float x, y, dx, dy, angle;
  bool thrust;
  Animation anim;
  string name;

  void settings(Animation &a, int X, int Y, float Angle = 0, int R = 1)
  {
    anim = a;
    x = X; y = Y;
    angle = Angle;
    radius = R;
  }

  void draw(RenderWindow &window)
  {
    anim.sprite.setPosition(x, y);
    anim.sprite.setRotation((angle + 90));  // controller of angle of spaceship
    anim.update();
    window.draw(anim.sprite);
    return ;
  }

  virtual void update() {};

};

class player: public Entity
{
public:

  player()
  {
    name = "player";
  }

  void update()
  {
    if (thrust)
    {
      dx += cos(angle * degToRad) * 0.5;
      dy += sin(angle * degToRad) * 0.5;
    }
    else
    {
      // Decay the dx and dy parameters
      dx *= 0.98;
      dy *= 0.98;
    }

    int speed = sqrt(pow(dx, 2) + pow(dy, 2));

    float maxspeed = 15;
    if (speed > maxspeed)
    {
      dx *= (maxspeed / speed);
      dy *= (maxspeed / speed);
    }

    x += dx;
    y += dy;

//    cout << "speed=" << sqrt(pow(dx, 2) + pow(dy, 2)) << endl;

    if (x > W)x = 0;  if (x < 0)x = W;
    if (y > H)y = 0;  if (y < 0)y = H;
  }
  // ANGLE WILL BE UPDATED IN MAIN FUNCTION
};

class Bullet: public Entity
{
public:

  Bullet()
  {
    name = "bullet";
  }

  void update()
  {
    dx = cos(angle * degToRad) * 6;
    dy = sin(angle * degToRad) * 6;

    x += dx;
    y += dy;

    // out of bound then life = 0;
    if (x > W or y > H or x < 0 or y < 0)
      life = 0;
  }

};

class Asteroid: public Entity
{
public:

  Asteroid()
  {
    dx = rand() % 8 - 4;
    dy = rand() % 8 - 4;

    if (dx == 0 and dy == 0)
    {
      dx++;
      dy++;
    }
    name = "asteroid";
  }

  void update()
  {
    x += dx;
    y += dy;

    if (x > W)x = 0;  if (x < 0)x = W;
    if (y > H)y = 0;  if (y < 0)y = H;
  }

};

int collided(Entity* a, Entity* b)
{
  // collision is when the distance between the two entities
  // is <= radii of the two entities
  float dist1 = sqrt( pow(a->x - b->x, 2) + pow(a->y - b->y, 2) ) ;
  float dist2 = a->radius + b->radius;

//  return (b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y) < (a->radius + b->radius) * (a->radius + b->radius);
  return dist1 <= dist2 ;

}

float asteroid_animation_speed  = .2 ;
float bullet_animation_speed    = .2 ;
float explosion_animation_speed = .5 ;

// Frame Rate
int frame_rate = 60 ;

// Radius for all
int radii = 20;

class Menu
{
  int index = 0,gap = 70;
  double x, y;
  Font font;
  vector<sf::Text>menu;
  int maxindex = 0;
  RenderWindow window;
  vector<string>str;

public:
  Menu(float X, float Y)
  {
    x = X;
    y = Y;
    font.loadFromFile("./fonts/DejaVuSans.ttf");
  };

  string getSelectedOption()
  {
    return str[index];
  }

  void add(string s)
  {
    str.push_back(s);
    Text t;
    t.setFont(font);
    t.setString(s);
    t.setCharacterSize(30);

    if (maxindex == 0)
    {
      t.setColor(Color::Green);
    }
    else
    {
      t.setColor(Color::White);
    }
    menu.push_back(t);
    maxindex++;
  }

  void MoveUp()
  {
    if (index - 1 >= 0)
    {
      menu[index].setColor(Color::White);
      index--;
      menu[index].setColor(Color::Green);
    }
  }

  void MoveDown()
  {
    if (index + 1 < maxindex)
    {
      menu[index].setColor(Color::White);
      index++;
      menu[index].setColor(Color::Green);
    }
  }

  void display(RenderWindow & window)
  {
    for (int i = 0; i < maxindex; i++)
    {
      menu[i].setPosition(x , y + (gap) * (i + 1) );
      window.draw(menu[i]);
    }
  }

};

///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int second_player = 0;
int asteroids = 1;
int first_player_lives = 3;
int second_player_lives = 3;

int collisions1, collisions2;
int asteroidcount = 0;

int main()
{

  RenderWindow window(VideoMode(W, H), "JC-Window");
  window.setFramerateLimit(frame_rate);

  srand(time(0));

  // Getting background
  Texture t1, t2, t3, t4, t5, t6, t7, t8, t9,t10;
  t1.loadFromFile("./images/spaceship.png");
  t2.loadFromFile("./images/background.jpg");
  t4.loadFromFile("./images/fire_red.png");
  t7.loadFromFile("./images/fire_blue.png");
  t5.loadFromFile("./images/rock.png");
  t6.loadFromFile("./images/explosions/type_C.png");

  t8.loadFromFile("./images/background2.jpg");
  t9.loadFromFile("./images/background3.jpg");
  t10.loadFromFile("./images/background4.jpg");

  t1.setSmooth(true);
  t2.setSmooth(true);

  Sprite background{t2};
  Sprite pause_background(t8);
  Sprite main_background(t9);
  Sprite gameover_background(t10);

  Animation static_player(t1, 40, 0, 40, 40, 1, 0);                             // count = 1, frames =0;
  Animation moving_player(t1, 40, 40, 40, 40, 1, 0);
  Animation bullet_animation(t4, 0, 0, 32, 64, 16, bullet_animation_speed);
  Animation bullet_animation_blue(t7, 0, 0, 32, 64, 16, bullet_animation_speed);
  Animation rock(t5, 0, 0, 64, 64, 16, asteroid_animation_speed);
  Animation explosion(t6, 0, 0, 256, 256, 48, explosion_animation_speed);

  static_player.sprite.rotate(90);

//  player * p = new player();
//  player * p2 = new player();
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

  int cc = 1;

  Font font;
  font.loadFromFile("./fonts/DejaVuSans.ttf");
  Text score;
  score.setFont(font);
  score.setString("SCORE ; 0");
  score.setCharacterSize(10);
  score.setPosition(10, 10);
  int scorecount = 0;

  Font font2;
  font2.loadFromFile("./fonts/DejaVuSans-Bold.ttf");

  Text heading;
  heading.setFont(font2);
  heading.setString("ASTEROID GAME");
  heading.setCharacterSize(40);
  heading.setPosition((330.0/1000)*W, (84.0/800)*H);
  heading.setColor(Color::Blue);

  Text gameover;
  gameover.setFont(font2);
  gameover.setString("GAME OVER");
  gameover.setCharacterSize(40);
  gameover.setPosition((330.0/1000)*W, (84.0/800)*H);
  gameover.setColor(Color::Red);


  Menu menu(W*(405.0/1000) , (H)*(344.0)/800 );
  menu.add("Single Player");
  menu.add("Multi Player");
  menu.add("No Asteroid GamePlay");
  menu.add("Exit");

  Menu menu2(W*(405.0/1000) , (H)*(344.0)/800 );
  menu2.add("Resume");
  menu2.add("Exit");

  Menu menu3(W*(405.0/1000) , (H)*(344.0)/800 );
  menu3.add("Play Again");
  menu3.add("Exit");

  vector<Entity*>entities;

///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
MainMenu:

  // Destroy all Entities
  second_player = 0;
  int entities_size = entities.size();
  for(int i=0;i<entities_size;i++)
  {
      entities.pop_back();
  }

  while (window.isOpen())
  {
    window.clear();

    int ok = 1;

    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        window.close();
        return 0;
      }
      if (event.type == Event::KeyPressed)
      {
        if (event.key.code == Keyboard::Up)
        {
          cout << "move up\n";
          menu.MoveUp();
        }
        else if (event.key.code == Keyboard::Down)
        {
          cout << "move down \n";
          menu.MoveDown();
        }
        else if (event.key.code == Keyboard::Enter)
        {
          if (menu.getSelectedOption() == "Single Player")
          {
            ok = 0;
            second_player=0;
            asteroids = 1;
            break;
          }
          else if (menu.getSelectedOption() == "Exit")
          {
            return 0;
          }
          else if (menu.getSelectedOption() == "Multi Player")
          {
              ok=0;
              second_player=1;
              asteroids = 1;
              break;
          }
          else if (menu.getSelectedOption() ==  "No Asteroid GamePlay")
          {
              ok=0;
              second_player=0;
              asteroids = 0;
              break;
          }
        }
      }
    }

    window.draw(main_background);

    menu.display(window);
    window.draw(heading);

    score.setString("Score : " + to_string(scorecount));
    window.draw(score);


    window.display();

    if (!ok)
    {
//        goto Restart;
      break;
    }
}


///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Create Entities

  player * p = new player();
  p->settings(static_player, (3.0 * W) / 4, (3.0 * H) / 4, 0, radii);
  p->id = 1;
  entities.pb(p);

  player * p2 = new player();
  p2->settings(static_player, W / 4, H / 4, 0, radii);
  p2->id = 2;

  if(second_player)
  {
    entities.pb(p2);
  }

  asteroidcount = 0;
  if(asteroids)
  {
    for (int i = 0; i < 10; i++)
    {
        asteroidcount++;
        Entity *a = new Asteroid();
        a->settings(rock, rand() % W, rand() % H, rand() % 360, radii);
        entities.pb(a);
    }
  }

goto GamePlay;
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

PauseMenu:
  while (window.isOpen())
  {
    window.clear();
//
    int ok = 1;

    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        window.close();
        return 0;
      }
      if (event.type == Event::KeyPressed)
      {
        if (event.key.code == Keyboard::Up)
        {
          cout << "move up\n";
          menu2.MoveUp();
        }
        else if (event.key.code == Keyboard::Down)
        {
          cout << "move down \n";
          menu2.MoveDown();
        }
        else if (event.key.code == Keyboard::Enter)
        {
          if (menu2.getSelectedOption() == "Resume")
          {
            ok = 0;
            goto GamePlay;
            break;
          }
          else if (menu2.getSelectedOption() == "Exit")
          {
            goto MainMenu;
          }
        }
      }
    }

    window.draw(pause_background);
    menu2.display(window);

    window.display();

    if (!ok)
    {
      break;
    }
  }


///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

GameOver:
  while (window.isOpen())
  {

    window.clear();
    int ok = 1;

    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        window.close();
        return 0;
      }
      if (event.type == Event::KeyPressed)
      {
        if (event.key.code == Keyboard::Up)
        {
          cout << "move up\n";
          menu3.MoveUp();
        }
        else if (event.key.code == Keyboard::Down)
        {
          cout << "move down \n";
          menu3.MoveDown();
        }
        else if (event.key.code == Keyboard::Enter)
        {
          if (menu3.getSelectedOption() == "Play Again")
          {
            ok = 0;
//            goto Restart;
            break;
          }
          else if (menu3.getSelectedOption() == "Exit")
          {
            goto MainMenu;
          }
        }
      }
    }

    window.draw(gameover_background);
    menu3.display(window);
    window.draw(gameover);

    window.display();

    if (!ok)
    {
      break;
    }
  }


///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

GamePlay:
    scorecount = 0;
    collisions1 = 0;
    collisions2 = 0;
  while (window.isOpen())
  {

    Event event;
    while (window.pollEvent(event))
    {
      // Handle Events here
      if (event.type == Event::Closed)
      {
        window.close();
        return 0;
      }

      if (event.type == Event::KeyPressed)
      {
        if (event.key.code == Keyboard::Space and p->life==1)
        {
          Entity *bullet = new Bullet();
          bullet->settings(bullet_animation, p->x, p->y, p->angle, radii);
          entities.pb(bullet);
        }
        if (second_player and p2->life == 1)
        {
          if ( event.key.code == Keyboard::Tab)
          {
            Entity *bullet = new Bullet();
            bullet->settings(bullet_animation_blue, p2->x, p2->y, p2->angle, radii);
            entities.pb(bullet);
          }
        }
      }

      else if (event.key.code == Keyboard::Escape)
      {
        window.clear();
        goto PauseMenu;
      }
//         else if(event.type == sf::Event::MouseButtonPressed)
//           {
//                if (event.mouseButton.button == Mouse::Left or event.mouseButton.button == Mouse::Right)
//                {
//                    std::cout << "the right button was pressed" << std::endl;
//                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
//                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
//                }
//           }
    }

    // For Continuous flow
    if(p->life==1)
    {
    if (Keyboard::isKeyPressed(Keyboard::Left)) { p->angle -= 5; }
    if (Keyboard::isKeyPressed(Keyboard::Right)) { p->angle += 5; }
    if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust = true;
    else p->thrust = false;
    }

    if (second_player and p2->life==1)
    {
      if (Keyboard::isKeyPressed(Keyboard::A)) { p2->angle -= 5; }
      if (Keyboard::isKeyPressed(Keyboard::D)) { p2->angle += 5; }
      if (Keyboard::isKeyPressed(Keyboard::W)) p2->thrust = true;
      else p2->thrust = false;
    }

    p->angle = ( ((int)p->angle % 360) + 360 ) % 360;

    if (second_player)
    {
      p2->angle = ( ((int)p2->angle % 360) + 360 ) % 360;
    }

    if (p->thrust)
    {
      p->anim = moving_player;
    }
    else
    {
      p->anim = static_player;
    }

    if (second_player)
    {
      if (p2->thrust)
      {
        p2->anim = moving_player;
      }
      else
      {
        p2->anim = static_player;
      }
    }

    window.draw(background);

///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    int cnt = 1;
    for (auto a : entities)
    {
      for (auto b : entities)
      {
        int destroyed = 0;

        if (a->name == "asteroid" and b->name == "bullet")
        {
          if (collided(a, b))
          {
            destroyed = 1;
            scorecount++;

            a->life = 0;
            b->life = 0;

            Entity* exp = new Entity();
            int xx = a->x;
            int yy = a->y;
            exp->settings(explosion, xx, yy);
            exp->name = "explosion";
            entities.pb(exp);
          }
        }

        else if (a->name == "asteroid" and b->name == "player")
        {
          if (collided(a, b))
          {
            destroyed = 1;
            a->life = 0;

            b->settings(static_player, W / 2, H / 2, 0, radii);
            b->dx = 0;
            b->dy = 0;

            if(b->id ==1)
            {
                collisions1 += 1;
                if(collisions1>=3)
                {
                    b->life=0;
                }
            }
            else{
                collisions2 += 1;
                 if(collisions2>=3)
                {
                    b->life=0;
                }
            }

            Entity* exp = new Entity();
            int xx = a->x;
            int yy = a->y;
            exp->settings(explosion, xx, yy);
            exp->name = "explosion";
            entities.pb(exp);

          }
        }

        if (destroyed)
        {
          // create a new asteroid
          asteroidcount--;
          int mx = rand() % 3;
          if(asteroidcount<20)
          {
          for (int i = 0; i < max(1,mx); i++)
          {
            asteroidcount++;
            Entity *a = new Asteroid();
            a->settings(rock, rand() % W, rand() % H, rand() % 360, radii);
            entities.pb(a);
          }
          }
        }
      }
    }

    if(collisions1>=3 and (collisions2>=3 or second_player==0))
    {
        goto MainMenu;
    }

    cout<<asteroidcount<<endl;

///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    for (int i = 0; i < entities.size(); i++)
    {
      if (entities[i]->name == "explosion" and entities[i]->anim.isEnd())
      {
        cout << "explosion ended" << endl;
        entities[i]->life = 0;
      }
      if (entities[i]->life == 0)
      {
        swap(entities[i], entities[entities.size() - 1]);
        entities.pop_back();
        i--;
      }
      else
      {
        entities[i]->update();
        entities[i]->draw(window);
      }
    }

///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    score.setString("Score : " + to_string(scorecount));
    window.draw(score);

    window.display();
  }

}
