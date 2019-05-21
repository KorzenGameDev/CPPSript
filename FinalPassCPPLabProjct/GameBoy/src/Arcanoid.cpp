#include "Library.h"

Arcanoid::Arcanoid(int l=1,int p=0,int t=0)
:level(l), points(p), tempPoints(t)
{

}

Arcanoid::~Arcanoid()
{
}

void Arcanoid::Setup()
{
    srand(time(0));

    window.create(VideoMode(width, height), "Arkanoid!");
    window.setFramerateLimit(60);

    LoadTextures();
    NextLevel();
    sf::Sprite sBackground(t2),sBall(t3), sPaddle(t4);
    sPaddle.setPosition(width/2,height-75);
    sf::Sprite block[300];

    SpawnBlock(block);

    while (window.isOpen())
    {
       Event e;
       while (window.pollEvent(e))
       {
         if (e.type == Event::Closed)
         {
            window.close();
            Menu menu;
            menu.Setup();
         }
       }



        PaddleController(sPaddle);
        Positioning(sBackground,sBall,sPaddle,block);

        window.clear();
            std::cout<<points-tempPoints<<std::endl;
            if((points-tempPoints) >= blockNumber*7)
            {
                NextLevel();
                SpawnBlock(block);
            }

            Draw(sBackground,sBall,sPaddle,block);
        window.display();
    }
}

void Arcanoid::Draw(sf::Sprite &sBackground, sf::Sprite &sBall, sf::Sprite &sPaddle , sf::Sprite *block)
{
    window.draw(sBackground);
    window.draw(sBall);
    window.draw(sPaddle);

    for (int i=0;i<blockNumber;i++)
        window.draw(block[i]);

    //////////////UPDATE SCORE/////////////
    sf::Font font;
    if(!font.loadFromFile("arial.ttf"))
        std::cout<<"ERROR LOAD FONT!"<<std::endl;

    sf::Text text;
    text.setFont(font);
    std::string number=std::to_string(points);
    std::string str="Points: "+number;
    text.setString(str);
    int offset=80;
    text.setPosition(width/2-offset,2);
    window.draw(text);
    //////////////END UPDATE/////////////
}

void Arcanoid::Positioning(sf::Sprite &sBackground, sf::Sprite &sBall, sf::Sprite &sPaddle , sf::Sprite *block)
{
    x+=dx;
    for (int i=0;i<blockNumber;i++)
        if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) )
        {
            block[i].setPosition(-100,0);
            GetPoint();
            dx=-dx;
        }

    y+=dy;
    for (int i=0;i<blockNumber;i++)
        if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) )
        {
            block[i].setPosition(-100,0);
            GetPoint();
            dy=-dy;
        }

    offsetXmin=170;
    offsetXmax=750;
    if (x<offsetXmin || x>offsetXmax)  dx=-dx;
    if (y<40)  dy=-dy;
    if(y>450)
    {
        window.close();
        Score score;
        score.DisplayScore(points);
    }

    if ( FloatRect(x,y,12,12).intersects(sPaddle.getGlobalBounds()) ) dy=-(rand()%5+2);

    sBall.setPosition(x,y);
}

void Arcanoid::PaddleController(sf::Sprite &sPaddle)
{
    int pos=sPaddle.getPosition().x;
    offsetXmin=170;
    offsetXmax=685;

    if(pos>offsetXmin)
        if (Keyboard::isKeyPressed(Keyboard::Left))
                sPaddle.move(-10,0);

    if(pos<offsetXmax)
        if (Keyboard::isKeyPressed(Keyboard::Right))
            sPaddle.move(10,0);
}

void Arcanoid::LoadTextures()
{
    /////////////LOAD TEXTURES////////////////
    t1.loadFromFile("images/arcanoid/block01.png");
    t2.loadFromFile("images/menu/nintendo.png");
    t3.loadFromFile("images/arcanoid/ball.png");
    t4.loadFromFile("images/arcanoid/paddle.png");

    std::cout<<"LOAD TEXTURES DONE"<<std::endl;
}

void Arcanoid::SpawnBlock(sf::Sprite *block)
{
    blockNumber=0;
    for (int i=4;i<=17;i++)
        for (int j=3;j<=10;j++)
          {
              int chance=rand()%10;
              if(chance<=6)
              {
                block[blockNumber].setTexture(t1);
                block[blockNumber].setPosition(i*43,j*20);
                blockNumber++;
              }
          }
}

void Arcanoid::NextLevel()
{
    level++;
    tempPoints=points;
    switch(level%5)
    {
        case 0:
        {
            t1.loadFromFile("images/arcanoid/block01.png");
            break;
        }
        case 1:
        {
            t1.loadFromFile("images/arcanoid/block02.png");
            break;
        }
        case 2:
        {
            t1.loadFromFile("images/arcanoid/block03.png");
            break;
        }
        case 3:
        {
            t1.loadFromFile("images/arcanoid/block04.png");
            break;
        }
        case 4:
        {
            t1.loadFromFile("images/arcanoid/block05.png");
            break;
        }
        default:
            std::cout<<"Next level bad call!!"<<std::endl;
            break;
    }
}

void Arcanoid::GetPoint()
{
    points+=10;
}

