#include "Library.h"

struct Position
{ int x,y;} snake[100],fruct,enemy[100], portal;

Snake::Snake(int l=1,int p=0,int t=0)
: level(l), points(0), tempPoints(0)
{
}

Snake::~Snake()
{
    //destructor
}

void Snake::Setup()
{
    window.create(sf::VideoMode(width , height), "Snake");
    LoadTextures();
    RandomMap();

    srand(time(0));

	Clock clock;
    float timer=0, delay=0.1;

    //DRAWING WINDOW PER FRAME
    while (window.isOpen())
    {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
        timer+=time;

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

        MoveController(); ///MOVE CONTROLLER FOR PLAYER

		if (timer>delay)
        {
            timer=0;
            ///CALLL END GAME IF DETECTION COLLISION IS TRUE
            if(DetectCollision())
            {
                window.close();
                Score score;
                score.DisplayScore(points);
            }

            //DOING ONE FRAME
            Frame();
        }

    ///DRAWING MAP!!!
        window.clear();

        Draw();
        window.display();
    }
    ///END DRAWING MAP!!!
}

void Snake::Frame()
{
    //move in frame
    for (int i= snakeSize ; i>0 ;--i)
    {
        snake[i].x=snake[i-1].x;
        snake[i].y=snake[i-1].y;
    }

    //direction move
    if (direction==0) snake[0].y+=1;
    if (direction==1) snake[0].x-=1;
    if (direction==2) snake[0].x+=1;
    if (direction==3) snake[0].y-=1;

    //spawn fruct if in map when we dont have fruct
    if(snake[0].x==fruct.x && snake[0].y==fruct.y)
    {
        snakeSize++;
        points+=10;
        SpawnFruct(); //    SPAWN FRUCT
    }

    Teleporting();//TELEPORTING IF WE DONT HAVE WALL

}

void Snake::Draw()
{
    /////////SPRITE///////////////////////////
	//BOARD
	sf::Sprite spriteMain(t10);
	sf::Sprite spriteBg(t9);
	sf::Sprite spriteBgWhite(t1);
	sf::Sprite spriteBgGray(t8);

	//PLAYER
	sf::Sprite spritePlayerHead(t7);
	sf::Sprite spritePlayer(t2);

	//ENEMY AND WALL
	sf::Sprite spriteEnemy(t3);
	sf::Sprite spriteWall(t4);

	//PICKABLE
	sf::Sprite spriteFruct(t5);
	sf::Sprite spritePortal(t6);
    /////////////////////////////////////////

    spriteMain.setPosition(0,0);
    window.draw(spriteMain);

    spriteBg.setPosition(0,0);
    window.draw(spriteBg);

    for (int i=offsetX; i<widthInSquare+offsetX; i++)
            for (int j=offsetY; j<heightInSquare+offsetY; j++)
            {
                if((i%2)==0)
                {
                    if((j%2)==0)
                    {
                        spriteBgWhite.setPosition(i*squareSize,j*squareSize);
                        window.draw(spriteBgWhite);
                    }
                    else
                    {
                        spriteBgGray.setPosition(i*squareSize,j*squareSize);
                        window.draw(spriteBgGray);
                    }
                }
                else
                {
                    if((j%2)==0)
                    {
                        spriteBgGray.setPosition(i*squareSize,j*squareSize);
                        window.draw(spriteBgGray);
                    }
                    else
                    {
                        spriteBgWhite.setPosition(i*squareSize,j*squareSize);
                        window.draw(spriteBgWhite);
                    }

                }

                //Generate wall and enemy;
                for(int k=0;k<enemies;k++)
                {
                    if((i==offsetX || i==widthInSquare-1+offsetX || j==offsetY || j==heightInSquare-1+offsetY)&& level>=10)
                    {
                        spriteWall.setPosition(i*squareSize,j*squareSize);
                        window.draw(spriteWall);
                    }
                    if(enemy[k].x==i && enemy[k].y==j)
                    {
                        spriteEnemy.setPosition(i*squareSize,j*squareSize);
                        window.draw(spriteEnemy);
                    }
                }
            }

        if(points-tempPoints==(10*level) && !portalExist)
        {
            while(!SpawnPortal()) {}///spawn portal to next level
        }

        if(snake[0].x==portal.x && snake[0].y==portal.y)
        {
            window.clear();
            UsePortal();
        }

        for (int i=0; i<snakeSize; i++)
        {
            if(i==0)
            {
                spritePlayerHead.setPosition(snake[i].x*squareSize,snake[i].y*squareSize);
                window.draw(spritePlayerHead);
            }
            else
            {
                spritePlayer.setPosition(snake[i].x*squareSize, snake[i].y*squareSize);
                window.draw(spritePlayer);
            }
        }

        spriteFruct.setPosition(fruct.x*squareSize,  fruct.y*squareSize);
        window.draw(spriteFruct);

        if(portalExist)
        {
            spritePortal.setPosition(portal.x*squareSize, portal.y*squareSize);
            window.draw(spritePortal);
        }

        //////////////UPDATE SCORE/////////////
        sf::Font font;
        if(!font.loadFromFile("RetroGaming.ttf"))
            std::cout<<"ERROR LOAD FONT!"<<std::endl;

        sf::Text text;
        text.setFont(font);
        std::string number=std::to_string(points);
        std::string str="Points: "+number;
        text.setString(str);
        int offset=80;
        text.setPosition(width/2 -offset,2);
        window.draw(text);
        //////////////END UPDATE/////////////
}

void Snake::LoadTextures()
{
	t1.loadFromFile("images/snake/white.png");
	t2.loadFromFile("images/snake/green.png");
	t3.loadFromFile("images/snake/enemy.png");
	t4.loadFromFile("images/snake/black.png");
	t5.loadFromFile("images/snake/food.png");
	t6.loadFromFile("images/snake/portal.png");
	t7.loadFromFile("images/snake/head.png");
	t8.loadFromFile("images/snake/gray.png");
	t9.loadFromFile("images/menu/nintendo.png");
	t10.loadFromFile("images/menu/bg.png");
	///////////////////////////////////////////
}

void Snake::RandomMap()
{
    srand(time(0));
    while(SpawnFruct());

    ///start position of player
    snake[0].x=5+offsetX;
    snake[0].y=5+offsetY;

    //Random position enemy
    for(int i=0; i<enemies; i++)
    {
        int x=rand() % widthInSquare-1;
        int y=rand() % heightInSquare-1;

        if(x==0) x=1;
        if(y==0) y=1;
        if(x<0) x=-x;
        if(y<0) y=-y;

        x=x+offsetX;
        y=y+offsetY;

        if(y!=5+offsetY && x!=10+offsetX)
        {
            enemy[i].x=x;
            enemy[i].y=y;
        }
    }

}

//player move
void Snake::MoveController()
{
    if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && direction!= 2) direction=1;
    if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && direction !=1)  direction=2;
    if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) && direction !=0) direction=3;
    if ((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && direction !=3) direction=0;
}

void Snake::Teleporting()
{
    if (snake[0].x > widthInSquare+offsetX)
        snake[0].x = offsetX;

    if (snake[0].x < offsetX)
        snake[0].x = widthInSquare+offsetX;

    if (snake[0].y > heightInSquare+offsetY)
        snake[0].y=offsetY;

    if (snake[0].y < offsetY)
        snake[0].y=heightInSquare+offsetY;
}

bool Snake::SpawnFruct()
{
    PositionFruct();
    for(int i=0; i<enemies; i++)
    {
        if(fruct.x==enemy[i].x && fruct.y==enemy[i].y)
        {
            return true;
        }
    }

    return false;
}

//spawn fruit
void Snake::PositionFruct()
{
    srand(time(0));
    fruct.x=rand() % widthInSquare-1;
    fruct.y=rand() % heightInSquare-1;

    if(fruct.x==0) fruct.x=1;
    if(fruct.y==0) fruct.y=1;
    if(fruct.x<0) fruct.x=-fruct.x;
    if(fruct.y<0) fruct.y=-fruct.y;

    fruct.x=fruct.x+offsetX;
    fruct.y=fruct.y+offsetY;

    //std::cout<<"Pozycja owoca x: "<<fruct.x<<" y: "<<fruct.y<<std::endl;

}

bool Snake::SpawnPortal()
{
    int x=rand() % (widthInSquare-1);
    int y=rand() % (heightInSquare-1);

    if(x==0) x=1;
    if(y==0) y=1;
    if(x<0) x=-x;
    if(y<0) y=-y;

    x=x+offsetX;
    y=y+offsetY;

    for(int i=0; i<enemies; i++)
        if(x==enemy[i].x && y==enemy[y].y)
            return false;
    for(int i=0; i<snakeSize; i++)
        if(x==snake[i].x && y==snake[i].y)
            return false;

    if(x==fruct.x && y==fruct.y)
        return false;

    portal.x=x;
    portal.y=y;

    //std::cout<<"Portal position x: " <<portal.x <<" y: "<<portal.y<<std::endl;

    portalExist =true;
    return true;
}

void Snake::UsePortal()
{
    level++;
    tempPoints=points;
    snakeSize=1;
    if(level<10)
        enemies=enemies+level;
    if(level==10)
        enemies=10;
    if(level>10)
        enemies+=level-6;

    portalExist=false;
    RandomMap();
}

bool Snake::DetectCollision()
{
    if((snake[0].x==offsetX || snake[0].x == widthInSquare-1+offsetX || snake[0].y==offsetY || snake[0].y==heightInSquare-1+offsetY)&& level>=10)
        return true;

    for(int i=1; i<snakeSize; i++)
    {
        if(snake[0].x==snake[i].x && snake[0].y==snake[i].y)
        {
            return true;
        }
    }

    for(int i=0; i<enemies; i++)
    {
        if(snake[0].x==enemy[i].x && snake[0].y==enemy[i].y)
        {
            return true;
        }
    }

    return false;
}


