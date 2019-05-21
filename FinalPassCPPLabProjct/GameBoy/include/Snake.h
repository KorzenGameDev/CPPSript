#ifndef SNAKE_H
#define SNAKE_H


class Snake
{
    public:
        Snake(int,int,int);
        virtual ~Snake();

        //Setup Game
        void Setup();

    private:
        void Frame(); // one frame in game
        void MoveController();
        bool DetectCollision();
        bool SpawnPortal();
        void UsePortal();
        void Teleporting();
        void Draw();
        void LoadTextures();

    ///RANDOM GENERATION MAP
        void RandomMap();

    ///Fruct
        void PositionFruct(); //set random position to fruct
        bool SpawnFruct(); //spawn in position fruct

    ///size
        int squareSize=16;
        int widthInSquare=40,heightInSquare=22;
        int widthInPixel = squareSize*widthInSquare, heightInPixel = squareSize*heightInSquare;
    ///end size

    ///to game
        sf::RenderWindow window;
        sf::Texture t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
        int offsetX=10;
        int offsetY=4;
        int direction=0,snakeSize=1;
        int enemies=10;
        int width=960, height=480;
        int points=0,tempPoints=0, level=1;
        bool portalExist=false;
        bool flip=false;
    ///end
};

#endif // SNAKE_H
