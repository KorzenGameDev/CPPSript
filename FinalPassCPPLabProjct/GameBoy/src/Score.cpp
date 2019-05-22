#include "Library.h"

Score::Score()
{
}

Score::~Score()
{
    //dtor
}

void Score::DisplayScore(int points)
{
    window.create(sf::VideoMode(width , height), "Score");
    while(window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                Menu menu;
                menu.Setup();
            }
		}

        window.clear();

        Texture t1,t2,t3;

        t3.loadFromFile("images/menu/bg.png");
        sf::Sprite spriteMain(t3);
        spriteMain.setPosition(0,0);
        window.draw(spriteMain);

        t2.loadFromFile("images/menu/nintendo.png");
        sf::Sprite spriteBg(t2);
        spriteBg.setPosition(0,0);
        window.draw(spriteBg);

        t1.loadFromFile("images/menu/gameover.png");
        Sprite spriteGameover(t1);
        int offsetX=220;
        int offsetY=50;
        spriteGameover.setPosition(offsetX,offsetY);
        window.draw(spriteGameover);

        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            window.close();
            Menu menu;
            menu.Setup();
        }

        sf::Font font;
        if(!font.loadFromFile("RetroGaming.ttf"))
            std::cout<<"ERROR LOAD FONT!"<<std::endl;

        sf::Text text;
        text.setFont(font);
        std::string num=std::to_string(points);

        std::string str="YOU EARN: "+num+" POINTS!";
        text.setString(str);
        offsetX=300;
        offsetY=250;
        text.setPosition(offsetX, offsetY);
        window.draw(text);

        window.display();
    }
}

void Score::DisplayScore()
{
    window.create(sf::VideoMode(width , height), "Score");
    while(window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                Menu menu;
                menu.Setup();
            }
		}

        window.clear();

        Texture t1,t2,t3;

        t3.loadFromFile("images/menu/bg.png");
        sf::Sprite spriteMain(t3);
        spriteMain.setPosition(0,0);
        window.draw(spriteMain);

        t2.loadFromFile("images/menu/nintendo.png");
        sf::Sprite spriteBg(t2);
        spriteBg.setPosition(0,0);
        window.draw(spriteBg);

        t1.loadFromFile("images/menu/gameover.png");
        Sprite spriteGameover(t1);
        int offsetX=220;
        int offsetY=50;
        spriteGameover.setPosition(offsetX,offsetY);
        window.draw(spriteGameover);

        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            window.close();
            Menu menu;
            menu.Setup();
        }

        sf::Font font;
        if(!font.loadFromFile("RetroGaming.ttf"))
            std::cout<<"ERROR LOAD FONT!"<<std::endl;

        sf::Text text;
        text.setFont(font);

        std::string str="Congratulation you lose!";
        text.setString(str);
        offsetX=300;
        offsetY=250;
        text.setPosition(offsetX, offsetY);
        window.draw(text);

        window.display();
    }
}

