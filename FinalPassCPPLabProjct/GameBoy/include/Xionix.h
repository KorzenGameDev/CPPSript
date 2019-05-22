#ifndef XIONIX_H
#define XIONIX_H

/**@brief przechowuje funkcje do gry xionix */
class Xionix
{
    public:
        /**@brief konstruktor
        *
        *@param[in] poziom
        */
        Xionix(int);
        /**@brief  destruktor */
        virtual ~Xionix();
        /**@brief zaladowuje wszystkie glowne funkcje - klasy menu */
        void Setup();
        const static int ROWS=21,COLUMNS=35;
        /**@brief struktura wroga*/
    struct Enemy{

        int x=0,y=0,dx=0,dy=0;
        int tileSize=18;

         /**@brief konstruktor wroga */
        Enemy()
        {
            x=y=300;
            dx=4-rand()%8;
            dy=4-rand()%8;
        }
         /**@brief poruszanie sie wroga
         *
         *@param[in] tablica dwuwymairowa planszy
         */
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
         /**@brief zapelnienie sie odcietych krawedzi mapy
         *
         *@param[in] tablica dwuwymiarowa planszy
         *@param[in] x
         *@param[in] y
          */
        void Drop(int grid[ROWS][COLUMNS],int,int);
         /**@brief zaladowuje tekstury */
        void LoadTextures();
         /**@brief sterowanie graczem*/
        void PlayerController();
         /**@brief poruszanie sie graczem
         *
         *@param[in] tablica dwywymiarowa planszy
         */
        void Move(int grid[ROWS][COLUMNS]);
         /**@brief nowy poziom w grze
         *
         *po wycieciu 300 kwadratow przenosi gracza na nastepny poziom
         @param[in] tablica dwuwymiarowa planszy
         */
        void NextLevel(int grid[ROWS][COLUMNS]);
         /**@brief wykonuje pojedyncza klatke w grze
         *
         *param[in] tablica dwuwymiarowa planszy
         *@param[in] tablica wrogow*/
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
