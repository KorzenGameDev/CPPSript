#ifndef XIONIX_H
#define XIONIX_H


class Xionix
{
    public:
        Xionix(int);
        virtual ~Xionix();
        void Setup();
        const static int ROWS=21,COLUMNS=35;
    struct Enemy{

        int x=0,y=0,dx=0,dy=0;
        int tileSize=18;

        Enemy()
        {
            x=y=300;
            dx=4-rand()%8;
            dy=4-rand()%8;
        }
        void Move(int grid[ROWS][COLUMNS])
        {
            x+=dx;
            if(grid[y/tileSize][x/tileSize]==1){
                dx=-dx;
                x+=dx;
            }

            y+=dy;
            if(grid[y/tileSize][x/tileSize]==1){
                dy=-dy;
                y+=dy;
    }}};
    private:
        void Drop(int grid[ROWS][COLUMNS],int,int);
        void LoadTextures();
        void PlayerController();
        void Move(int grid[ROWS][COLUMNS]);
        void NextLevel(int grid[ROWS][COLUMNS]);
        void Frame(int grid[ROWS][COLUMNS],Enemy enemy[100]);

        int width=960, height=480;
        const static int tileSize=18;
        int enemyCount = 1;
        float timer=0, delay=0.07;
        int level=1;
        int temp=-108;
        int offsetX=9;
        int offsetY=3;
        int x=0, y=0, dx=0, dy=0;

        sf::RenderWindow window;
        sf::Texture t1,t2,t3,t4,t9,t10;
};

#endif // XIONIX_H
