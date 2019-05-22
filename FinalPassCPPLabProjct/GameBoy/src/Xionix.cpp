#include "Library.h"

Xionix::Xionix(int l=1)
:level(l)
{}

Xionix::~Xionix()
{}

void Xionix::Setup()
{
    srand(time(0));
    Clock clock;
    int grid[ROWS][COLUMNS]={0};

	window.create(VideoMode(width, height), "Xonix");
	window.setFramerateLimit(60);

    LoadTextures();

    ////////////SET SPRITE//////////////////////
	sf::Sprite spriteHead(t1),spriteBody(t2),spriteWall(t3), spriteEnemy(t4), spriteBg(t9), spriteMain(t10);
	spriteEnemy.setOrigin(20,20);
    ///////////SET SPRITE/////////////////////////

    //+++CREATE ENEMY HOLDER////
    Enemy enemy[100];

	for (int i=0;i<ROWS;i++)
        for (int j=0;j<COLUMNS;j++)
            if (i==0 || j==0 || i==ROWS-1 || j==COLUMNS-1)
                grid[i][j]=1;

    while (window.isOpen())
    {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer+=time;

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

        /////////////PLAYER CONTOLLER//////////
        PlayerController();
        Move(grid);
        Frame(grid,enemy);

        /////////DRAW//////////
        window.clear();
        spriteMain.setPosition(0,0);
        window.draw(spriteMain);

        spriteBg.setPosition(0,0);
        window.draw(spriteBg);
        for (int i=0;i<ROWS;i++)
            for (int j=0;j<COLUMNS;j++)
            {
                if (grid[i][j]==0) continue;
                if (grid[i][j]==1)
                {
                    spriteWall.setPosition((j+offsetX)*tileSize,(i+offsetY)*tileSize);
                    window.draw(spriteWall);
                }
                if (grid[i][j]==2)
                {
                    spriteBody.setPosition((j+offsetX)*tileSize,(i+offsetY)*tileSize);
                    window.draw(spriteBody);
                }
            }

        spriteHead.setPosition((x+offsetX)*tileSize,(y+offsetY)*tileSize);
        window.draw(spriteHead);

        spriteEnemy.rotate(10);
        for (int i=0;i<enemyCount;i++)
        {
            int x=enemy[i].x;
            int y=enemy[i].y;
            spriteEnemy.setPosition(x+(offsetX*18),y+(offsetY*18));
            window.draw(spriteEnemy);
        }

        sf::Font font;
        if(!font.loadFromFile("RetroGaming.ttf"))
            std::cout<<"ERROR LOAD FONT!"<<std::endl;

        sf::Text text;
        text.setFont(font);
        std::string num=std::to_string(temp);

        std::string str=num+" /300";
        text.setString(str);
        text.setPosition(width/2-100, 0);
        window.draw(text);

        window.display();
	}
}

void Xionix::PlayerController()
{
        if (Keyboard::isKeyPressed(Keyboard::Left)) {dx=-1;dy=0;};
	    if (Keyboard::isKeyPressed(Keyboard::Right))  {dx=1;dy=0;};
	    if (Keyboard::isKeyPressed(Keyboard::Up)) {dx=0;dy=-1;};
		if (Keyboard::isKeyPressed(Keyboard::Down)) {dx=0;dy=1;};
}

void Xionix::Drop(int grid[ROWS][COLUMNS],int y,int x)
{
  if (grid[y][x]==0) grid[y][x]=-1;
  if (grid[y-1][x]==0) Drop(grid,y-1,x);
  if (grid[y+1][x]==0) Drop(grid,y+1,x);
  if (grid[y][x-1]==0) Drop(grid,y,x-1);
  if (grid[y][x+1]==0) Drop(grid,y,x+1);
}

void Xionix::Move(int grid[ROWS][COLUMNS])
{
    if (timer>delay)
    {
         x+=dx;
         y+=dy;

         if (x<0) x=0;
         if (x>COLUMNS-1) x=COLUMNS-1;
         if (y<0) y=0;
         if (y>ROWS-1) y=ROWS-1;

         if (grid[y][x]==2)
         {
             window.close();
             Score score;
             score.DisplayScore();
         }

         if (grid[y][x]==0) grid[y][x]=2;
         timer=0;
    }
}

void Xionix::LoadTextures()
{
    switch(level%5)
    {
        case 0:
            {
                t1.loadFromFile("images/xionix/red.png");
                t2.loadFromFile("images/xionix/green.png");
                t3.loadFromFile("images/xionix/blue.png");
                break;
            }
        case 1:
            {
                t1.loadFromFile("images/xionix/red.png");
                t2.loadFromFile("images/xionix/yellow.png");
                t3.loadFromFile("images/xionix/orange.png");
                break;
            }
        case 2:
            {
                t1.loadFromFile("images/xionix/purple.png");
                t2.loadFromFile("images/xionix/lightBlue.png");
                t3.loadFromFile("images/xionix/darkBlue.png");
                break;
            }
        case 3:
            {
                t1.loadFromFile("images/xionix/orange.png");
                t2.loadFromFile("images/xionix/yellow.png");
                t3.loadFromFile("images/xionix/lightBlue.png");
                break;
            }
        case 4:
            {
                t1.loadFromFile("images/xionix/green.png");
                t2.loadFromFile("images/xionix/blue.png");
                t3.loadFromFile("images/xionix/purple.png");
                break;
            }
        default:
            {
                t1.loadFromFile("images/xionix/red.png");
                t2.loadFromFile("images/xionix/green.png");
                t3.loadFromFile("images/xionix/blue.png");
                break;
            }
    }

    t4.loadFromFile("images/xionix/enemy.png");
    t9.loadFromFile("images/menu/nintendo.png");
    t10.loadFromFile("images/menu/bg.png");
}

void Xionix::Frame(int grid[ROWS][COLUMNS],Enemy enemy[100])
{
    for(int i=0;i<enemyCount;i++)
            enemy[i].Move(grid);

    if(grid[y][x]==1)
    {
        dx=dy=0;

        for (int i=0;i<enemyCount;i++)
            Drop(grid,enemy[i].y/tileSize, enemy[i].x/tileSize);

        for (int i=0;i<ROWS;i++)
            for (int j=0;j<COLUMNS;j++)
                if (grid[i][j]==-1)
                    grid[i][j]=0;
                else grid[i][j]=1;
    }

    for(int i=0;i<enemyCount;i++)
        if(grid[enemy[i].y/tileSize][enemy[i].x/tileSize]==2)
        {
            window.close();
            Score score;
            score.DisplayScore();
        }

    temp=-108;
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLUMNS;j++)
            if(grid[i][j]==1)
                temp++;

    if(300<=temp)
        NextLevel(grid);

}

void Xionix::NextLevel(int grid[ROWS][COLUMNS])
{
    level++;
    temp=-108;
    enemyCount=level;
    x=0;y=0;dx=0;dy=0;
    for(int i=0; i<ROWS;i++)
        for(int j=0; j<COLUMNS;j++)
        {
            if(i==0 || j==0 || j==COLUMNS-1 || i==ROWS-1)
                grid[i][j]=1;
            else grid[i][j]=0;
        }
    LoadTextures();
}
