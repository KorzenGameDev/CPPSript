#ifndef SNAKE_H
#define SNAKE_H

/**@brief przechowuje funkcje do gry snake */
class Snake
{
    public:
        /**@brief konstruktor
        *
        *@param[in] poziom
        *@param[in] liczba punktow
        *@param[in] tymczasowa liczba punktow
        */
        Snake(int,int,int);
        /**@brief destruktor */
        virtual ~Snake();

        //Setup Game
        /**@brief zaladowuje wszystkie glowne funkcje - klasy menu */
        void Setup();

        /**@brief struktura przechowujaca wspolrzedne obiektow na mapie */
        struct Position
        { int x,y;} snake[100],fruct,enemy[100], portal;


    private:
        /**@brief odpowiada za kazda pojedyncza kaltke w grze */
        void Frame(); // one frame in game
        /**@brief poruszanie wezem */
        void MoveController();
        /**@brief wykrywa kolizje weza z obiektami */
        bool DetectCollision();
        /**@brief po przekroczeniu danej liczby pkt tworzy i pozycjonuje portal do nast poziomu */
        bool SpawnPortal();
        /**@brief przenosi gracza do nowego poziomu  */
        void UsePortal();
        /**@brief jesli nie ma scian odpowiada za poruszanie weza na krawedziach mapy */
        void Teleporting();
        /**@brief rysuje okno gry z szata graficzna snake'a  */
        void Draw();
        /**@brief  laduje tekstury*/
        void LoadTextures();

    ///RANDOM GENERATION MAP
    /**@brief generuje losowa mape
    *
    * sposob losowy usrtala pozycje wrogow pozycje scian jesli istnieja pozycje weza
    * i pozycje pierwszego owoca
    */
        void RandomMap();

    ///Fruct
    /**@brief pozycjonuje owoc */
        void PositionFruct(); //set random position to fruct
        /**@brief tworzy i wyswietla owoc
        *
        *@return zwraca prawde jesli owoc zostal stworzony poprawnie
         */
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
        int level,points,tempPoints;
        bool portalExist=false;
        bool flip=false;
    ///end
};

#endif // SNAKE_H
