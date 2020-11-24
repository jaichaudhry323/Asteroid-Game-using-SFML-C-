using namespace sf;
using namespace std;
void HelloWorld()
{

    sf::RenderWindow window(sf::VideoMode(800, 200), "Hello from SFML");

    // Create a "Text" object called "message". Weird but we will learn about objects soon
    sf::Text message;

    // We need to choose a font
    sf::Font font;
    font.loadFromFile("28 Days Later.ttf");

    // Set the font to our message
    message.setFont(font);

    // Assign the actual message
    message.setString("Hello world");

    // Make it really big
    message.setCharacterSize(100);

    // Choose a color
    message.setFillColor(sf::Color::White);

    // This "while" loop goes round and round- perhaps forever
    while (window.isOpen())
    {
        // The next 6 lines of code detect if the window is closed
        // And then shuts down the program
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Someone closed the window- bye
                window.close();
        }

        // Clear everything from the last run of the while loop
        window.clear();

        // Draw our message
        window.draw(message);

        // Show everything we just drew
        window.display();
    }

}


// #################################################################################
// #################################################################################


void SampleWindow()
{

    RenderWindow window(VideoMode(640,700),"Name");

    while(window.isOpen())
    {
        Event event ;

        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                {
                    window.close();
                }
        }
    }
}


// #################################################################################
// #################################################################################


void KeyStrokeAnalysis()
{
    RenderWindow window(VideoMode(700,500),"LOL");

    while(window.isOpen())
    {
        window.display();
        Event event;
        while(window.pollEvent(event))
        {
//           cout<<event.type<<endl;

           if(event.type == Event::Closed)
           {
               window.close();
               return ;
           }
           else if(event.type == Event::KeyPressed)
           {
               if(event.key.code == Keyboard::Space)
               {
                   cout<<"SpaceBar Pressed"<<endl;
               }
               else if(event.key.code == Keyboard::Down)
               {
                   cout<<"Down Pressed"<<endl;
               }
               else if(event.key.code == Keyboard::Up)
               {
                   cout<<"Up Pressed"<<endl;
               }
               else if(event.key.code == Keyboard::Left)
               {
                   cout<<"Left Pressed"<<endl;
               }
               else if(event.key.code == Keyboard::Right)
               {
                   cout<<"Right Pressed"<<endl;
               }
               else if(event.key.code == Keyboard::D)
               {
                   cout<<"D Pressed"<<endl;
               }
               else if(event.key.code == Keyboard::S)
               {
                   cout<<"S Pressed"<<endl;
               }
               else if(event.key.code == Keyboard::A)
               {
                   cout<<"A Pressed"<<endl;
               }
               else if(event.key.code == Keyboard::W)
               {
                   cout<<"W Pressed"<<endl;
               }
           }
           else if(event.type == sf::Event::Resized)
            {
                std::cout << "new width: " << event.size.width << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }
           else if(event.type == Event::TextEntered)
           {
               if(event.text.unicode < 128)
               {
                   cout<<"Character typed = "<<static_cast<char>(event.text.unicode)<<endl;
               }
           }

           else if(event.type == sf::Event::MouseButtonPressed)
           {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
           }
        }
    }
}


// #################################################################################
// #################################################################################


void MovingShapes()
{
      RenderWindow window(VideoMode(640,700),"Name");
    // Make three circles with 50 pixels radius
    // called circleRed, circle Green and circleBlue
    sf::CircleShape circleRed(50);
    sf::CircleShape circleGreen(50);
    sf::CircleShape circleBlue(50);

    // Color the circles appropriately
    circleRed.setFillColor(sf::Color(255, 0, 0));
    circleGreen.setFillColor(sf::Color(0, 255, 0));
    circleBlue.setFillColor(sf::Color(0, 0, 255));

    // Here's the variables stuff
    float xGreen = 200;
    float yGreen = 200;

    float xBlue = 300;
    float yBlue = 300;

    // Position the red circle at x,y 100,100 "Hard-coded"
    circleRed.setPosition(100, 100);
    circleGreen.setPosition(xGreen, yGreen);
    circleBlue.setPosition(xBlue, yBlue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Someone closed the window- bye
                window.close();
        }

        // Clear everything from the last run of the while loop
        window.clear();

        // Process game logic, AI, movement etc
        // Increase xGreen by one hundreth each game frame
        xGreen = xGreen + .01;
        yGreen = yGreen - .01;
        xBlue = xBlue + .03;
        yBlue = yBlue + .03;

        // Position the green circle at the postion -
        // stored in xGreen and yGreen
        circleGreen.setPosition(xGreen, yGreen);

        // Position the blue circle at the postion -
        // stored in xBlue and yBlue
        circleBlue.setPosition(xBlue, yBlue);

        // Draw our game scene here
        //Draw the cirlces
        window.draw(circleRed);
        window.draw(circleGreen);
        window.draw(circleBlue);

        // Show everything on the screen
        window.display();

    }
}


// #################################################################################
// #################################################################################


void DrawingShapes()
{
      RenderWindow window(VideoMode(900,900),"LOL");

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            // handle events here
            if(event.type == Event::Closed)
            {
                window.close();
                return ;
            }
        }

        sf::RectangleShape rectangle{ { 220.f, 160.f } };
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition({ 150.f, 20.f });
        rectangle.rotate(20.f);


        sf::CircleShape circle{ 100.f };
        circle.setFillColor(sf::Color{Color::Red });
        circle.setOutlineColor(sf::Color{ 224, 160, 37, 255 });
        circle.setOutlineThickness(5);
        circle.setPosition({ 300.f, 395.f });

        sf::ConvexShape trapezoid{ 4 };
        trapezoid.setPoint(0, { 100.f, 0.f });
        trapezoid.setPoint(1, { 0.f, 200.f });
        trapezoid.setPoint(2, { 600.f, 200.f });
        trapezoid.setPoint(3, { 500.f, 0.f });
        trapezoid.setFillColor(sf::Color{ Color::Blue });
        trapezoid.setPosition({ 100.f, 600.f });

        // ...
        window.clear();
        window.draw(rectangle);
        window.draw(circle);
        window.draw(trapezoid);
        window.display();

    }
}


// #################################################################################
// #################################################################################


void TexturesAndSprites()
{
    int cnt=0;
    Texture texture;
    RenderWindow window(VideoMode(1000,1000),"LOL");

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            // handle events here
            if(event.type == Event::Closed)
            {
                window.close();
                return ;
            }
        }

        window.clear(sf::Color::Black);

        if(!texture.loadFromFile("./images/sfml.png"))
        {
            cout<<"DIDNT LOAD THE IMG"<<endl ;
            return ;
        }

        Sprite logo{texture};
        logo.setPosition({300,300});

        Sprite partial_logo{texture};
        partial_logo.setTextureRect({0,0,50,50});  // x ,y , len in x, len in y
        partial_logo.setPosition({100,100});

        Font font;
        if (!font.loadFromFile("./fonts/DejaVuSans.ttf")) {
        return ;
        }

        sf::Text meeting_cpp{"Graphics Project", font, 60 };
        meeting_cpp.setPosition({ 900.f, 500.f });
        meeting_cpp.setStyle(sf::Text::Bold);
        meeting_cpp.rotate(180);

        Text sfml{ "SFML", font, 80 };
        sfml.setPosition({ 100 , 700 });
        sfml.setFillColor(sf::Color::White);
        sfml.setOutlineColor(sf::Color{ Color::Green });
        sfml.setOutlineThickness(5);
        sfml.setLetterSpacing(1.5);

        window.draw(logo);
        window.draw(partial_logo);
        window.draw(meeting_cpp);
        window.draw(sfml);
        window.display();
    }
}


// #################################################################################
// #################################################################################


void HardObjectMotion()
{
    int val = 0;
    int xpos = 0,ypos = 0;
    int thrust = 0;
    int scrw,scrh;

    Texture t1;
    if(!t1.loadFromFile("./images/spaceship.png"))
    {
        cout<<"Error loading spaceship.png"<<endl;
        return ;
    }

    scrw=1000;
    scrh=1000;
    xpos = scrw/2;
    ypos = scrh/2;
    RenderWindow window(VideoMode(scrw,scrh),"JC-Window");

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            // Handle Events here
            if(event.type == Event::Closed)
            {
                window.close();
                return ;
            }
            if(event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Space)
                    thrust = 1-thrust;

                if(event.key.code == Keyboard::Left)
                {
                    xpos-=5;
                    if(xpos<=0)
                        xpos=scrw;
                    if(xpos>=1000)
                        xpos=0;
                }

                if(event.key.code == Keyboard::Right)
                {
                    xpos+=5;
                    if(xpos<=0)
                        xpos=scrw;
                    if(xpos>=1000)
                        xpos=0;
                }
                if(event.key.code == Keyboard::Down)
                {
                    ypos+=5;
                    if(ypos<=0)
                        ypos=scrh;
                    if(ypos>=1000)
                        ypos=0;
                }
                if(event.key.code == Keyboard::Up)
                {
                    ypos-=5;
                    if(ypos<=0)
                        ypos=scrh;
                    if(ypos>=1000)
                        ypos=0;
                }
            }

        }

        window.clear();

        t1.setSmooth(true);

        if(thrust)
        val = 40 - val;

        Sprite spaceship{t1};
        spaceship.setTextureRect({40,val,40,40});
        spaceship.setPosition(xpos,ypos);

        window.draw(spaceship);
        window.display();

    }
}


///X#################################################################################
///X#################################################################################

///X## GENERATION ONE MOVEMENT

//////#include<SFML/Graphics.hpp>
//////#include<bits/stdc++.h>
//////#include "Testing_Functions.h"
//////
//////#define pb push_back
//////using namespace std;
//////using namespace sf;
//////
//////float degToRad = 3.14/180;
//////int H,W;
//////
//////class Animation
//////{
//////public:
//////        float frame,speed;
//////        Sprite sprite;
//////        vector<IntRect>frames;
//////
//////        Animation(){}
//////
//////        Animation(Texture &t,int x,int y,int w,int h,int count,float spd)
//////        {
//////            speed = spd;
//////            frame = 0;
//////
//////            for(int i=0;i<count;i++)
//////                frames.pb(IntRect(x+i*w,y,w,h));
//////
//////            sprite.setTexture(t);
//////            sprite.setPosition(w/2,h/2);
//////
//////            sprite.setTextureRect(frames[0]);
//////
//////        }
//////
//////        void update()
//////        {
//////            frame += speed;
//////
//////            if(frame >= frames.size()) frame -= frames.size();
//////
//////            sprite.setTextureRect( frames[ (int)frame ] );
//////        }
//////
////////        bool isEnd()
////////        {
////////            return frame+speed >= frames.size();
////////        }
//////};
//////
//////
//////class Entity
//////{
//////    public:
//////    float x,y,dx,dy,angle;
//////    bool life;
//////    string name;
//////    Animation anim;
//////
//////    Entity()
//////    {
//////        life = 1;
//////    }
//////
//////    void settings(Animation &a,int X,int Y,float Angle=0,int radius=1)
//////    {
//////        anim = a;
//////        x = X;
//////        y = Y;
//////        angle = Angle;
////////        R = radius;
//////    }
//////
//////    virtual void update(){};
//////
////////    void draw(RenderWindow &window)
////////    {
////////        window.sprite.setPosition(x,y);
////////        window.sprite.setRotation(angle);
////////        window.draw(anim.sprite);
////////
////////        return ;
////////    }
//////
//////    virtual ~Entity(){};
//////
//////};
//////
//////class player
//////{
//////public:
//////    float x,y,dx,dy,angle;
//////    bool thrust;
//////    Animation anim;
//////    string name;
//////
//////    player()
//////    {
//////        name = "player";
//////    }
//////
//////    void settings(Animation &a,int x,int y,int angle)
//////    {
//////        this->x = x;
//////        this->y = y;
//////        this-> angle = angle;
//////        anim = a;
//////        anim.sprite.setRotation(angle+90);
//////    }
//////
//////    void update()
//////    {
//////        if(thrust)
//////        {
//////            dx = cos(angle*degToRad)*.4;
//////            dy = sin(angle*degToRad)*.4;
//////        }
//////        else
//////        {
//////            // Decay the dx and dy parameters
//////            dx*=0.8;
//////            dy*=0.8;
//////        }
//////
//////        x += dx;
//////        y += dy;
//////
//////        if(x>W)x=0;  if(x<0)x=W;
//////        if(y>H)y=0;  if(y<0)y=H;
//////    }
//////    // ANGLE WILL BE UPDATED IN MAIN FUNCTION
//////
//////    void draw(RenderWindow &window)
//////    {
//////        update();
//////        anim.sprite.setPosition(x,y);
//////        anim.sprite.setRotation((angle+90));
//////        window.draw(anim.sprite);
//////
//////        return ;
//////    }
//////
//////};
//////
//////int main()
//////{
//////    H = 800;
//////    W = 1000;
//////
//////// ## FRAMES AND ANIMATION
//////
//////    Texture t1;
//////    if(!t1.loadFromFile("./images/spaceship.png"))
//////    {
//////        cout<<"Error loading spaceship.png"<<endl;
//////        return 0;
//////    }
//////
//////    RenderWindow window(VideoMode(W,H),"JC-Window");
//////
//////    Animation animation(t1,40,0,40,40,1,0);    // count =1, frames =0;
//////    animation.sprite.rotate(90);
//////
//////    player * p = new player();
//////
//////    p->settings(animation,W/2,H/2,0);
//////
//////    while(window.isOpen())
//////    {
//////        Event event;
//////        while(window.pollEvent(event))
//////        {
//////            // Handle Events here
//////            if(event.type == Event::Closed)
//////            {
//////                window.close();
//////                return 0;
//////            }
//////        }
//////
//////    if (Keyboard::isKeyPressed(Keyboard::Right)) p->angle+=0.5;
//////    if (Keyboard::isKeyPressed(Keyboard::Left))  p->angle-=0.5;
//////    if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust=true;
//////    else p->thrust=false;
//////
//////
////////                if(event.key.code == Keyboard::Left)
////////                {
////////                    p->angle += 10;
////////                }
////////
////////                if(event.key.code == Keyboard::Right)
////////                {
////////                   p->angle -=10 ;
////////                }
////////                if(event.key.code == Keyboard::Down)
////////                {
////////                   p->thrust = 1;
////////                }
////////                else
////////                {
////////                    p->thrust = 0;
////////                }
//////
//////
//////        window.clear();
//////
//////        t1.setSmooth(true);
//////
//////        p->draw(window);
//////
//////        window.display();
//////    }
//////
//////
//////}
//////
//////
//////





///X////////////////////////////////////////////////////////////////////
///X######################################################################
///######################################################################
///X/////////////////////////////////////////////////////////////////////







//////#include<SFML/Graphics.hpp>
//////#include<bits/stdc++.h>
//////#include "Testing_Functions.h"
//////
//////#define pb push_back
//////using namespace std;
//////using namespace sf;
//////
//////float degToRad = 3.14/180;
//////int H,W;
//////
//////class Animation
//////{
//////public:
//////        float frame,speed;
//////        Sprite sprite;
//////        vector<IntRect>frames;
//////
//////        Animation(){}
//////
//////        Animation(Texture &t,int x,int y,int w,int h,int count,float spd)
//////        {
//////            speed = spd;
//////            frame = 0;
//////
//////            for(int i=0;i<count;i++)
//////                frames.pb(IntRect(x+i*w,y,w,h));
//////
//////            sprite.setTexture(t);
//////            sprite.setPosition(w/2,h/2);
//////
//////            sprite.setTextureRect(frames[0]);
//////
//////        }
//////
//////        void update()
//////        {
//////            frame += speed;
//////
//////            if(frame >= frames.size()) frame -= frames.size();
//////
//////            sprite.setTextureRect( frames[ (int)frame ] );
//////        }
//////
////////        bool isEnd()
////////        {
////////            return frame+speed >= frames.size();
////////        }
//////};
//////
//////
//////class Entity
//////{
//////    public:
//////    float x,y,dx,dy,angle;
//////    bool life;
//////    string name;
//////    Animation anim;
//////
//////    Entity()
//////    {
//////        life = 1;
//////    }
//////
//////    void settings(Animation &a,int X,int Y,float Angle=0,int radius=1)
//////    {
//////        anim = a;
//////        x = X;
//////        y = Y;
//////        angle = Angle;
////////        R = radius;
//////    }
//////
//////    virtual void update(){};
//////
////////    void draw(RenderWindow &window)
////////    {
////////        window.sprite.setPosition(x,y);
////////        window.sprite.setRotation(angle);
////////        window.draw(anim.sprite);
////////
////////        return ;
////////    }
//////
//////    virtual ~Entity(){};
//////
//////};
//////
//////class player
//////{
//////public:
//////    float x,y,dx,dy,angle;
//////    bool thrust;
//////    Animation anim;
//////    string name;
//////
//////    player()
//////    {
//////        name = "player";
//////    }
//////
//////    void settings(Animation &a,int x,int y,int angle)
//////    {
//////        this->x = x;
//////        this->y = y;
//////        this-> angle = angle;
//////        anim = a;
//////        anim.sprite.setRotation(angle+90);
//////    }
//////
//////    void update()
//////    {
//////        if(thrust)
//////        {
//////            dx = cos(angle*degToRad)*.4;
//////            dy = sin(angle*degToRad)*.4;
//////        }
//////        else
//////        {
//////            // Decay the dx and dy parameters
//////            dx*=0.8;
//////            dy*=0.8;
//////        }
//////
//////        x += dx;
//////        y += dy;
//////
//////        if(x>W)x=0;  if(x<0)x=W;
//////        if(y>H)y=0;  if(y<0)y=H;
//////    }
//////    // ANGLE WILL BE UPDATED IN MAIN FUNCTION
//////
//////    void draw(RenderWindow &window)
//////    {
//////        update();
//////        anim.sprite.setPosition(x,y);
//////        anim.sprite.setRotation((angle+90));
//////        window.draw(anim.sprite);
//////
//////        return ;
//////    }
//////};
//////
//////int main()
//////{
//////    H = 800;
//////    W = 1000;
//////
//////    // Getting background
//////    Texture t2;
//////    t2.loadFromFile("./images/background.jpg");
//////    Sprite background{t2};
//////
//////    // ## FRAMES AND ANIMATION
//////
//////    Texture t1;
//////    if(!t1.loadFromFile("./images/spaceship.png"))
//////    {
//////        cout<<"Error loading spaceship.png"<<endl;
//////        return 0;
//////    }
//////
//////    RenderWindow window(VideoMode(W,H),"JC-Window");
////////    window.setFramerateLimit(10);
//////
//////    Animation animation(t1,40,0,40,40,1,0);    // count =1, frames =0;
//////    animation.sprite.rotate(90);
//////
//////    player * p = new player();
//////
//////    p->settings(animation,W/2,H/2,0);
//////
//////    while(window.isOpen())
//////    {
//////        Event event;
//////        while(window.pollEvent(event))
//////        {
//////            // Handle Events here
//////            if(event.type == Event::Closed)
//////            {
//////                window.close();
//////                return 0;
//////            }
//////        }
//////
//////    if (Keyboard::isKeyPressed(Keyboard::Right)) p->angle+=0.5;
//////    if (Keyboard::isKeyPressed(Keyboard::Left))  p->angle-=0.5;
//////    if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust=true;
//////    else p->thrust=false;
//////
////////                if(event.key.code == Keyboard::Left)
////////                {
////////                    p->angle += 10;
////////                }
////////
////////                if(event.key.code == Keyboard::Right)
////////                {
////////                   p->angle -=10 ;
////////                }
////////                if(event.key.code == Keyboard::Down)
////////                {
////////                   p->thrust = 1;
////////                }
////////                else
////////                {
////////                    p->thrust = 0;
////////                }
//////
//////        window.clear();
//////
//////        t1.setSmooth(true);
//////        window.draw(background);
//////        p->draw(window);
//////
//////        window.display();
//////    }
//////
//////
//////}





///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX



////#include<SFML/Graphics.hpp>
////#include<bits/stdc++.h>
//////#include "Testing_Functions.h"
////
////#define pb push_back
////using namespace std;
////using namespace sf;
////
////float degToRad = 3.14/180;
////int H,W;
////
////class Animation
////{
////public:
////        float frame,speed;
////        Sprite sprite;
////        vector<IntRect>frames;
////
////        Animation(){}
////
////        Animation(Texture &t,int x,int y,int w,int h,int count,float spd)
////        {
////            speed = spd;
////            frame = 0;
////
////            for(int i=0;i<count;i++)
////                frames.pb(IntRect(x+i*w,y,w,h));
////
////            sprite.setTexture(t);
//////            sprite.setPosition(w/2,h/2);
////
////            sprite.setTextureRect(frames[0]);
////        }
////
////        void update()
////        {
////            frame += speed;
////            if(frame >= frames.size()) frame -= frames.size();
////            sprite.setTextureRect( frames[ (int)frame ] );
////        }
////
//////        bool isEnd()
//////        {
//////            return frame+speed >= frames.size();
//////        }
////};
////
////
////class Entity
////{
////    public:
////    float x,y,dx,dy,angle;
////    bool life;
////    string name;
////    Animation anim;
////
////    Entity()
////    {
////        life = 1;
////    }
////
////    void settings(Animation &a,int X,int Y,float Angle=0,int radius=1)
////    {
////        anim = a;
////        x = X;
////        y = Y;
////        angle = Angle;
//////        R = radius;
////    }
////
////    virtual void update(){};
////
//////    void draw(RenderWindow &window)
//////    {
//////        window.sprite.setPosition(x,y);
//////        window.sprite.setRotation(angle);
//////        window.draw(anim.sprite);
//////
//////        return ;
//////    }
////
////};
////
////class player
////{
////public:
////    int life = 1;
////    float x,y,dx,dy,angle;
////    bool thrust;
////    Animation anim;
////    string name;
////
////    player()
////    {
////        name = "player";
////    }
////
////    void settings(Animation &a,int x,int y,int angle)
////    {
////        this->x = x;
////        this->y = y;
////        this-> angle = angle;
////        anim = a;
////        anim.sprite.setRotation(angle+90);
////    }
////
////    void update()
////    {
////        if(thrust)
////        {
////            dx = cos(angle*degToRad)*4.5;
////            dy = sin(angle*degToRad)*4.5;
////        }
////        else
////        {
////            // Decay the dx and dy parameters
////            dx*=0.8;
////            dy*=0.8;
////        }
////
////        if(thrust)
////        {
////        x += dx;
////        y += dy;
////        }
////
////        if(x>W)x=0;  if(x<0)x=W;
////        if(y>H)y=0;  if(y<0)y=H;
////    }
////    // ANGLE WILL BE UPDATED IN MAIN FUNCTION
////
////    void draw(RenderWindow &window)
////    {
////        update();
////        anim.sprite.setPosition(x,y);
////        anim.sprite.setRotation((angle+90));    // controller of angle of spaceship
////        window.draw(anim.sprite);
////
////        return ;
////    }
////};
////
////class Bullet
////{
////public:
////    int x, y, dx, dy, angle;
////    string name = "bullet";
////    Animation anim;
////    int life = 1;
////
////    void update()
////    {
////        dx = cos(angle*degToRad)*4;
////        dy = sin(angle*degToRad)*4;
////
////        x+=dx;
////        y+=dy;
////
////        // out of bound then life = 0;
////        if(x>W or y>H or x<0 or y<0)
////            life = 0;
////    }
////
////    void settings(Animation &a,int x,int y,int angle)
////    {
////        this->x = x;
////        this->y = y;
////        this-> angle = angle;
////        anim = a;
////        anim.sprite.setRotation(angle+90);
////    }
////
////    void draw(RenderWindow &window)
////    {
////        update();
////        anim.sprite.setPosition(x,y);
////        anim.sprite.setRotation(angle+90);
////        window.draw(anim.sprite);
////    }
////
////};
////
////
////int main()
////{
////    H = 800;
////    W = 1000;
////
////    // Getting background
////    Texture t1,t2,t3,t4;
////    t2.loadFromFile("./images/background.jpg");
////    t4.loadFromFile("./images/fire_red.png");
////    Sprite background{t2};
////
////    vector<Bullet*>bullets;
////
////    // ## FRAMES AND ANIMATION
////    if(!t1.loadFromFile("./images/spaceship.png"))
////    {
////        cout<<"Error loading spaceship.png"<<endl;
////        return 0;
////    }
////
////    RenderWindow window(VideoMode(W,H),"JC-Window");
////    window.setFramerateLimit(60);
////
////    Animation static_player(t1,40,0,40,40,1,0);    // count =1, frames =0;
////    Animation moving_player(t1,40,40,40,40,1,0);
////    Animation bullet_animation(t4,0,0,30,40,16,10);
////
//////    static_player.sprite.rotate(90);
////
////    player * p = new player();
////    p->settings(static_player,W/2,H/2,0);
////
////
////    while(window.isOpen())
////    {
////        Event event;
////        while(window.pollEvent(event))
////        {
////            // Handle Events here
////            if(event.type == Event::Closed)
////            {
////                window.close();
////                return 0;
////            }
////
////             if(event.key.code == Keyboard::Space)
////             {
////                Bullet *bullet = new Bullet();
////                bullet->settings(bullet_animation,p->x,p->y,p->angle);
////                bullets.pb(bullet);
////             }
////        }
////
////    // For Continuous flow
////    if (Keyboard::isKeyPressed(Keyboard::Right)){ p->angle += 5; cout<<"right Pressed"<<endl;}
////    if (Keyboard::isKeyPressed(Keyboard::Left))  p->angle -= 5;
////    if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust=true;
////    else p->thrust=false;
////
////    p->angle = ( ((int)p->angle % 360) + 360 )%360;
////
//////
//////    if(Keyboard::isKeyPressed(Keyboard::Space))
//////    {
//////        Bullet *bullet = new Bullet();
//////        bullet->settings(bullet_animation,p->x,p->y,p->angle);
//////        bullets.pb(bullet);
//////    }
////
////    if(p->thrust)
////    {
////        p->anim = moving_player;
////    }
////    else
////    {
////        p->anim = static_player;
////    }
////
//////                if(event.key.code == Keyboard::Left)
//////                {
//////                    p->angle += 10;
//////                }
//////
//////                if(event.key.code == Keyboard::Right)
//////                {
//////                   p->angle -=10 ;
//////                }
//////                if(event.key.code == Keyboard::Down)
//////                {
//////                   p->thrust = 1;
//////                }
//////                else
//////                {
//////                    p->thrust = 0;
//////                }
////
////        window.clear();
////
////        t1.setSmooth(true);
////        window.draw(background);
////        p->draw(window);
////
////        for(int i=0;i<bullets.size();i++)
////        {
////            if(bullets[i]->life == 0)
////            {
////                swap(bullets[i],bullets[bullets.size()-1]);
////                bullets.pop_back();
////                i--;
////            }
////            else
////            {
////                bullets[i]->update();
////                bullets[i]->draw(window);
////            }
////        }
////
////        cout<<bullets.size()<<endl;
////
//////        cout<<p->angle<<endl;
////
////        window.display();
////    }
////
////
////}




///X////////////////////////////////////////////////////////////
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///X///////////////////////////////////////////////////////////




////#include<SFML/Graphics.hpp>
////#include<bits/stdc++.h>
//////#include "Testing_Functions.h"
////
////#define pb push_back
////using namespace std;
////using namespace sf;
////
////float degToRad = 3.14/180;
////int H,W;
////
////class Animation
////{
////public:
////        float frame,speed;
////        Sprite sprite;
////        vector<IntRect>frames;
////
////        Animation(){}
////
////        Animation(Texture &t,int x,int y,int w,int h,int count,float spd)
////        {
////            speed = spd;
////            frame = 0;
////
////            for(int i=0;i<count;i++)
////                frames.pb(IntRect(x+i*w,y,w,h));
////
////            sprite.setTexture(t);
//////            sprite.setPosition(w/2,h/2);
////
////            sprite.setTextureRect(frames[0]);
////        }
////
////        void update()
////        {
////            frame += speed;
////            if(frame >= frames.size()) frame -= frames.size();
////            sprite.setTextureRect( frames[ (int)frame ] );
////        }
////
//////        bool isEnd()
//////        {
//////            return frame+speed >= frames.size();
//////        }
////};
////
////
////class Entity
////{
////    public:
////    float x,y,dx,dy,angle;
////    bool life;
////    string name;
////    Animation anim;
////
////    Entity()
////    {
////        life = 1;
////    }
////
////    void settings(Animation &a,int X,int Y,float Angle=0,int radius=1)
////    {
////        anim = a;
////        x = X;
////        y = Y;
////        angle = Angle;
//////        R = radius;
////    }
////
////    virtual void update(){};
////
//////    void draw(RenderWindow &window)
//////    {
//////        window.sprite.setPosition(x,y);
//////        window.sprite.setRotation(angle);
//////        window.draw(anim.sprite);
//////
//////        return ;
//////    }
////
////};
////
////class player
////{
////public:
////    int life = 1;
////    float x,y,dx,dy,angle;
////    bool thrust;
////    Animation anim;
////    string name;
////
////    player()
////    {
////        name = "player";
////    }
////
////    void settings(Animation &a,int x,int y,int angle)
////    {
////        this->x = x;
////        this->y = y;
////        this-> angle = angle;
////        anim = a;
////        anim.sprite.setRotation(angle+90);
////    }
////
////    void update()
////    {
////        if(thrust)
////        {
////            dx = cos(angle*degToRad)*4.5;
////            dy = sin(angle*degToRad)*4.5;
////        }
////        else
////        {
////            // Decay the dx and dy parameters
////            dx*=0.8;
////            dy*=0.8;
////        }
////
////        if(thrust)
////        {
////        x += dx;
////        y += dy;
////        }
////
////        if(x>W)x=0;  if(x<0)x=W;
////        if(y>H)y=0;  if(y<0)y=H;
////    }
////    // ANGLE WILL BE UPDATED IN MAIN FUNCTION
////
////    void draw(RenderWindow &window)
////    {
////        update();
////        anim.sprite.setPosition(x,y);
////        anim.sprite.setRotation((angle+90));    // controller of angle of spaceship
////        window.draw(anim.sprite);
////
////        return ;
////    }
////};
////
////class Bullet
////{
////public:
////    int x, y, dx, dy, angle;
////    string name = "bullet";
////    Animation anim;
////    int life = 1;
////
////    void update()
////    {
////        dx = cos(angle*degToRad)*4;
////        dy = sin(angle*degToRad)*4;
////
////        x+=dx;
////        y+=dy;
////
////        // out of bound then life = 0;
////        if(x>W or y>H or x<0 or y<0)
////            life = 0;
////    }
////
////    void settings(Animation &a,int x,int y,int angle)
////    {
////        this->x = x;
////        this->y = y;
////        this-> angle = angle;
////        anim = a;
////        anim.sprite.setRotation(angle+90);
////    }
////
////    void draw(RenderWindow &window)
////    {
////        update();
////        anim.sprite.setPosition(x,y);
////        anim.sprite.setRotation(angle+90);
////        window.draw(anim.sprite);
////    }
////};
////
////class Asteroid
////{
////public:
////    int x, y, dx, dy, angle;
////    string name = "asteroid";
////    Animation anim;
////    int life = 1;
////
////    // position will be random
////    // and
////    // dx and dy increments will automatically determine angle
////
////    Asteroid()
////    {
////        dx = rand()%4 - 2;
////        dy = rand()%4 - 2;
////
////        if(dx==0 and dy==0)
////        {
////            dx++;
////            dy++;
////        }
////    }
////
////    void update()
////    {
//////        dx = cos(angle*degToRad)*4;
//////        dy = sin(angle*degToRad)*4;
////
////        x+=dx;
////        y+=dy;
////
////        if(x>W)x=0;  if(x<0)x=W;
////        if(y>H)y=0;  if(y<0)y=H;
////    }
////
////    void settings(Animation &a,int x,int y,int angle)
////    {
////        this->x = x;
////        this->y = y;
////        this-> angle = angle;
////        anim = a;
////        anim.sprite.setRotation(angle+90);
////    }
////
////    void draw(RenderWindow &window)
////    {
////        update();
////        anim.sprite.setPosition(x,y);
////        anim.sprite.setRotation(angle);
////        window.draw(anim.sprite);
////    }
////
////
////};
////
////
////int main()
////{
////    srand(time(0));
////
////    H = 800;
////    W = 1000;
////
////    // Getting background
////    Texture t1,t2,t3,t4,t5;
////    t2.loadFromFile("./images/background.jpg");
////    t4.loadFromFile("./images/fire_red.png");
////    t5.loadFromFile("./images/rock.png");
////
////    Sprite background{t2};
////
////    vector<Bullet*>bullets;
////    vector<Asteroid*>asteroids;
////
////    // ## FRAMES AND ANIMATION
////    if(!t1.loadFromFile("./images/spaceship.png"))
////    {
////        cout<<"Error loading spaceship.png"<<endl;
////        return 0;
////    }
////
////    RenderWindow window(VideoMode(W,H),"JC-Window");
////    window.setFramerateLimit(40);
////
////    t1.setSmooth(true);
////    t2.setSmooth(true);
////
////    Animation static_player(t1,40,0,40,40,1,0);    // count =1, frames =0;
////    Animation moving_player(t1,40,40,40,40,1,0);
////    Animation bullet_animation(t4,0,0,30,40,16,10);
////    Animation rock(t5,0,0,65,60,16,1);
////
//////    static_player.sprite.rotate(90);
////
////    player * p = new player();
////    p->settings(static_player,W/2,H/2,0);
////
////    for(int i=0;i<20;i++)
////    {
////        Asteroid *a = new Asteroid();
////        a->settings(rock,rand()%W,rand()%H,rand()%360);
////        asteroids.pb(a);
////    }
////
////    while(window.isOpen())
////    {
////        Event event;
////        while(window.pollEvent(event))
////        {
////            // Handle Events here
////            if(event.type == Event::Closed)
////            {
////                window.close();
////                return 0;
////            }
////
////             if(event.key.code == Keyboard::Space)
////             {
////                Bullet *bullet = new Bullet();
////                bullet->settings(bullet_animation,p->x,p->y,p->angle);
////                bullets.pb(bullet);
////             }
////        }
////
////    // For Continuous flow
////    if (Keyboard::isKeyPressed(Keyboard::Left)) { p->angle -= 5; cout<<"Left Pressed"<<endl;}
////    if (Keyboard::isKeyPressed(Keyboard::Right)){ p->angle += 5; cout<<"right Pressed"<<endl;}
////    if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust=true;
////    else p->thrust=false;
////
////    p->angle = ( ((int)p->angle % 360) + 360 )%360;
////
////
//////    if(Keyboard::isKeyPressed(Keyboard::Space))
//////    {
//////        Bullet *bullet = new Bullet();
//////        bullet->settings(bullet_animation,p->x,p->y,p->angle);
//////        bullets.pb(bullet);
//////    }
////
////    if(p->thrust)
////    {
////        p->anim = moving_player;
////    }
////    else
////    {
////        p->anim = static_player;
////    }
////
//////    if(event.key.code == Keyboard::Left)
//////    {
//////        p->angle += 10;
//////    }
//////
//////    if(event.key.code == Keyboard::Right)
//////    {
//////       p->angle -=10 ;
//////    }
//////    if(event.key.code == Keyboard::Down)
//////    {
//////       p->thrust = 1;
//////    }
//////    else
//////    {
//////        p->thrust = 0;
//////    }
////
////        window.clear();
////
////        t1.setSmooth(true);
////        window.draw(background);
////        p->draw(window);
////
////        for(int i=0;i<bullets.size();i++)
////        {
////            if(bullets[i]->life == 0)
////            {
////                swap(bullets[i],bullets[bullets.size()-1]);
////                bullets.pop_back();
////                i--;
////            }
////            else
////            {
////                bullets[i]->update();
////                bullets[i]->draw(window);
////            }
////        }
////
////        for(int i=0;i<asteroids.size();i++)
////        {
////            asteroids[i]->update();
////            asteroids[i]->draw(window);
////        }
////
////        cout<<bullets.size()<<endl;
////
////        window.display();
////    }
////
////
////}


///##############################################
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///##############################################

// Testing Menu
//
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"


void MenuTesting(RenderWindow &window)
{
//	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						return;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		menu.draw(window);

		window.display();
	}
}



///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


//
//#include<SFML/Graphics.hpp>
//#include<bits/stdc++.h>
////#include "Testing_Functions.h"
//#define run cout<<__LINE__<<endl;
//#define pb push_back
//using namespace std;
//using namespace sf;
//
//float degToRad = 3.14/180;
//int H=800,W=1000;
//
//class Animation
//{
//public:
//        float frame,speed;
//        Sprite sprite;
//        vector<IntRect>frames;
//
//        Animation(){}
//
//        Animation(Texture &t,int x,int y,int w,int h,int count,float spd)
//        {
//            speed = spd;
//            frame = 0;
//
//            for(int i=0;i<count;i++)
//                frames.pb(IntRect(x+i*w,y,w,h));
//
//            sprite.setTexture(t);
//            sprite.setOrigin(w/2,h/2);
////            sprite.setRotation(90);
//
//            sprite.setTextureRect(frames[0]);
//        }
//
//        void update()
//        {
//            frame += speed;
//            if(frame >= frames.size()) frame -= frames.size();
//            if(frames.size()>0)sprite.setTextureRect( frames[ (int)frame ] );
//        }
//
//        int isEnd()
//        {
//            return frame + speed >=frames.size();
//        }
//};
//
//
//class Entity
//{
//    public:
//    int life = 1,radius;
//    float x,y,dx,dy,angle;
//    bool thrust;
//    Animation anim;
//    string name;
//
//    void settings(Animation &a,int X,int Y,float Angle=0,int R=1)
//    {
//         anim = a;
//         x=X; y=Y;
//         angle = Angle;
//         radius = R;
//    }
//
//    void draw(RenderWindow &window)
//    {
////        update();
//        anim.sprite.setPosition(x,y);
//        anim.sprite.setRotation((angle+90));    // controller of angle of spaceship
//        anim.update();
//        window.draw(anim.sprite);
//
//        return ;
//    }
//
//    virtual void update(){};
//
//};
//
//class player:public Entity
//{
//public:
//
//    player()
//    {
//        name = "player";
//    }
//
//    void update()
//    {
//        if(thrust)
//        {
//            dx = cos(angle*degToRad)*4.2;
//            dy = sin(angle*degToRad)*4.2;
//        }
//        else
//        {
//            // Decay the dx and dy parameters
//            dx*=0.99;
//            dy*=0.99;
//        }
//
//        if(thrust)
//        {
//        x += dx;
//        y += dy;
//        }
//
//        if(x>W)x=0;  if(x<0)x=W;
//        if(y>H)y=0;  if(y<0)y=H;
//    }
//    // ANGLE WILL BE UPDATED IN MAIN FUNCTION
//
//};
//
//class Bullet:public Entity
//{
//public:
//
//    Bullet()
//    {
//        name = "bullet";
//    }
//
//    void update()
//    {
//        dx = cos(angle*degToRad)*4;
//        dy = sin(angle*degToRad)*4;
//
//        x+=dx;
//        y+=dy;
//
//        // out of bound then life = 0;
//        if(x>W or y>H or x<0 or y<0)
//            life = 0;
//    }
//
//};
//
//class Asteroid:public Entity
//{
//public:
//
//    Asteroid()
//    {
//         dx=rand()%8-4;
//         dy=rand()%8-4;
//
//        if(dx==0 and dy==0)
//        {
//            dx++;
//            dy++;
//        }
//        name = "asteroid";
//
////        anim.speed = asteroid_animation_speed;
//    }
//
//    void update()
//    {
////        dx = cos(angle*degToRad)*4;
////        dy = sin(angle*degToRad)*4;
//
//        x+=dx;
//        y+=dy;
//
//        if(x>W)x=0;  if(x<0)x=W;
//        if(y>H)y=0;  if(y<0)y=H;
//    }
//
//};
//
//int collided(Entity* a, Entity* b)
//{
//    // collision is when the distance between the two entities
//    // is <= radii of the two entities
//    float dist1 = sqrt( pow(a->x - b->x,2) + pow(a->y - b->y,2) ) ;
//    float dist2 = a->radius + b->radius;
////
////    cout<<a->name<<" "<<b->name<<endl;
////    cout<<dist1<<" "<<dist2<<endl;
//    return (b->x - a->x)*(b->x - a->x)+(b->y - a->y)*(b->y - a->y)<(a->radius + b->radius)*(a->radius + b->radius);
//    return dist1 <= dist2 ;
//
//}
//
//// Movement Speed
////float player_speed   = 1 ;
////float asteroid_speed = 1 ;
////float bullet_speed   = 1 ;
//
//// Animation speed
//float asteroid_animation_speed  = .2 ;
//float bullet_animation_speed    = .2 ;
//float explosion_animation_speed = .5 ;
//
//// Frame Rate
//int frame_rate = 60 ;
//
//// Radius for all
//int radii = 20;
//
//
//class Menu
//{
//    int index=0;
//    Font font;
//    vector<sf::Text>menu;
//    int maxindex=0;
//    RenderWindow window;
//    vector<string>str;
//
//public:
//    Menu()
//    {
//        font.loadFromFile("./fonts/DejaVuSans.ttf");
//    };
//
//    string getSelectedOption()
//    {
//        return str[index];
//    }
//
//    void add(string s)
//    {
//        str.push_back(s);
//        Text t;
//        t.setFont(font);
//        t.setString(s);
//        t.setCharacterSize(20);
//
//        if(maxindex==0)
//        {
//            t.setColor(Color::Green);
//        }
//        else
//        {
//            t.setColor(Color::White);
//        }
//        menu.push_back(t);
//        maxindex++;
//    }
//
//    void MoveUp()
//    {
//        if(index-1>=0)
//        {
//            cout<<index<<endl;
//            menu[index].setColor(Color::White);
//            index--;
//            menu[index].setColor(Color::Green);
//        }
//    }
//
//    void MoveDown()
//    {
//        if(index+1<maxindex)
//        {
//            cout<<index<<endl;
//            menu[index].setColor(Color::White);
//            index++;
//            menu[index].setColor(Color::Green);
//        }
//    }
//
//    void display(RenderWindow & window)
//    {
//        for(int i=0;i<maxindex;i++)
//        {
////            menu[i].setString(str[i]);
////            run
////            run
//            menu[i].setPosition(W/4, ( ((H-400)*1.0) / maxindex ) *(i+1) );
//            window.draw(menu[i]);
//        }
//    }
//};
//
//int main()
//{
//
//    RenderWindow window(VideoMode(W,H),"JC-Window");
//    window.setFramerateLimit(frame_rate);
//
/////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
////    MenuTesting(window);
////    KeyStrokeAnalysis();
////    return 0;
//
////    sf::CircleShape circleRed(20);
////
////    // Color the circles appropriately
////    circleRed.setFillColor(sf::Color(255, 0, 0));
////    // Position the red circle at x,y 100,100 "Hard-coded"
////    circleRed.setPosition(500, 500);
////
////    while(window.isOpen())
////    {
////        sf::Event event;
////        while (window.pollEvent(event))
////        {
////            if (event.type == sf::Event::Closed)
////                // Someone closed the window- bye
////                window.close();
////        }
////
////        window.draw(circleRed);
////        window.display();
////    }
////
////    return 0;
//
/////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//
//    srand(time(0));
//
//    // Getting background
//    Texture t1,t2,t3,t4,t5,t6;
//    t1.loadFromFile("./images/spaceship.png");
//    t2.loadFromFile("./images/background.jpg");
//    t4.loadFromFile("./images/fire_red.png");
//    t5.loadFromFile("./images/rock.png");
//    t6.loadFromFile("./images/explosions/type_C.png");
//
//    t1.setSmooth(true);
//    t2.setSmooth(true);
//
//    Sprite background{t2};
//
//    vector<Entity*>entities;
//
//    // ## FRAMES AND ANIMATION
////    if(!t1.loadFromFile("./images/spaceship.png"))
////    {
////        cout<<"Error loading spaceship.png"<<endl;
////        return 0;
////    }
//    Font font;
//    font.loadFromFile("./fonts/DejaVuSans.ttf");
//    Text score;
//    score.setFont(font);
//    score.setString("SCORE ; 0");
//    score.setCharacterSize(10);
//    score.setPosition(10,10);
//    int scorecount = 0;
//
//    Animation static_player(t1,40,0,40,40,1,0);    // count =1, frames =0;
//    Animation moving_player(t1,40,40,40,40,1,0);
//    Animation bullet_animation(t4,0,0,32,64,16,bullet_animation_speed);
//    Animation rock(t5,0,0,64,64,16,asteroid_animation_speed);
//    Animation explosion(t6,0,0,256,256,48,explosion_animation_speed);
//
//    static_player.sprite.rotate(90);
//
//    player * p = new player();
//    p->settings(static_player,W/2,H/2,0,radii);
//    entities.pb(p);
//
//    for(int i=0;i<10;i++)
//    {
//        Entity *a = new Asteroid();
//        a->settings(rock,rand()%W,rand()%H,rand()%360,radii);
//        entities.pb(a);
//    }
//
//    int cc=1;
//
//    //    cc--;
//
//    Menu menu;
////    run
//    menu.add("Start");
////    run
//    menu.add("Settings");
////    run
//    menu.add("Exit");
//
//MainMenu:
//    while(window.isOpen())
//    {
//    window.clear();
//    int ok=1;
//
//    Event event;
//    while(window.pollEvent(event))
//    {
//        if(event.type == Event::Closed)
//        {
//            window.close();
//            return 0;
//        }
//        if(event.type == Event::KeyPressed)
//        {
//            if(event.key.code == Keyboard::Up)
//            {
//                cout<<"move up\n";
//                menu.MoveUp();
//            }
//            else if(event.key.code == Keyboard::Down)
//            {
//                cout<<"move down \n";
//                menu.MoveDown();
//            }
//            else if(event.key.code == Keyboard::Enter)
//            {
//                if(menu.getSelectedOption()=="Start")
//               {
//                    ok=0;
//                    break;
//               }
//               else if(menu.getSelectedOption()=="Exit")
//               {
//                   return 0;
//               }
//               else if(menu.getSelectedOption()=="Settings")
//               {
//                   // goto settings page
//               }
//            }
//        }
//    }
//    window.draw(background);
//    menu.display(window);
//    window.display();
//
//    if(!ok)
//    {
//        break;
//    }
//}
//
//
//    while(window.isOpen())
//    {
//        cout<<1;
//        Event event;
//        while(window.pollEvent(event))
//        {
//            // Handle Events here
//            if(event.type == Event::Closed)
//            {
//                window.close();
//                return 0;
//            }
//
//            if(event.type == Event::KeyPressed)
//             if(event.key.code == Keyboard::Space)
//             {
//                Entity *bullet = new Bullet();
//                bullet->settings(bullet_animation,p->x,p->y,p->angle,radii);
//                entities.pb(bullet);
//             }
//
//             else if(event.key.code == Keyboard::Escape)
//             {
//                 window.clear();
//                 goto MainMenu;
//             }
////         else if(event.type == sf::Event::MouseButtonPressed)
////           {
////                if (event.mouseButton.button == Mouse::Left or event.mouseButton.button == Mouse::Right)
////                {
////                    std::cout << "the right button was pressed" << std::endl;
////                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
////                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
////                }
////           }
//        }
//
//    // For Continuous flow
//    if (Keyboard::isKeyPressed(Keyboard::Left)) { p->angle -= 5; }
//    if (Keyboard::isKeyPressed(Keyboard::Right)){ p->angle += 5; }
//    if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust=true;
//    else p->thrust=false;
//
//    p->angle = ( ((int)p->angle % 360) + 360 )%360;
//
//    if(p->thrust)
//    {
//        p->anim = moving_player;
//    }
//    else
//    {
//        p->anim = static_player;
//    }
//
////        window.clear();
//
//        window.draw(background);
////        p->update();
////        p->draw(window);
//        int cnt = 1;
//
//        for(auto a:entities)
//        {
//            for(auto b:entities)
//            {
////                if(cnt)
////                cout<<"analyzing\n", cnt -= 1;
//
//                if(a->name == "asteroid" and b->name == "bullet")
//                {
//                    if(collided(a,b))
//                    {
//                        scorecount++;
//                        cout<<"asteroid and bullet collided\n";
//                        cout<<"asteroid Coordinates : ";
//                        cout<<a->x<<" "<<a->y<<endl;
//                        cout<<"Bullet Coordinates : ";
//                        cout<<b->x<<" "<<b->y<<endl;
//                        cout<<endl;
//                        a->life = 0;
//                        b->life = 0;
//
//
//                    Entity* exp = new Entity();
//                    int xx = a->x;
//                    int yy = a->y;
//                    exp->settings(explosion,xx,yy);
//                    exp->name = "explosion";
//                    entities.pb(exp);
//
//                    // create a small rock pending
//                    }
//
//                }
//
//                else if(a->name == "asteroid" and b->name == "player")
//                {
//                    if(collided(a,b))
//                    {
//                        cout<<"asteroid and player collided\n";
//                        cout<<"asteroid Coordinates : ";
//                        cout<<a->x<<" "<<a->y<<endl;
//                        cout<<"Player Coordinates : ";
//                        cout<<b->x<<" "<<b->y<<endl;
//                        cout<<endl;
//
//                        a->life=0;
//
//                        b->settings(static_player,W/2,H/2,0,radii);
//                        b->dx=0;
//                        b->dy=0;
//
//                    Entity* exp = new Entity();
//                    int xx = a->x;
//                    int yy = a->y;
//                    exp->settings(explosion,xx,yy);
//                    exp->name = "explosion";
//                    entities.pb(exp);
//
//                    }
//
//                }
//            }
//        }
//
//        for(int i=0;i<entities.size();i++)
//        {
////            if(entities[i]->name =="explosion")
////            {
////                cout<<"ongoing explosion coordinates\n";
////                cout<<entities[i]->x<<" "<<entities[i]->y<<endl;
////            }
//            if(entities[i]->name =="explosion" and entities[i]->anim.isEnd())
//            {
//               cout<<"explosion ended"<<endl;
//               entities[i]->life = 0;
//            }
//            if(entities[i]->life == 0)
//            {
//                swap(entities[i],entities[entities.size()-1]);
//                entities.pop_back();
//                i--;
//            }
//            else
//            {
//                entities[i]->update();
//                entities[i]->draw(window);
//            }
////            cout<<entities[i]->name<<" "<<entities[i]->life<<endl;
//        }
//        score.setString("Score : " + to_string(scorecount));
//        window.draw(score);
//
//        window.display();
//    }
//
//
//}



