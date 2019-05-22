#ifndef SCORE_H
#define SCORE_H

/**@brief przechowuje funkcje do wyswietlania punktow*/
class Score
{
    public:
        /**@brief konstruktor */
        Score();
        /**@brief destruktor*/
        virtual ~Score();
        /**@brief zaprzyjaznienie z klasa snake*/
        friend class Snake;
        /**@brief zaprzyjaznienie z klasa arcanoid*/
        friend class Arcanoid;
         /**@brief zaprzyjaznienie z klasa Xionix*/
        friend class Xionix;
    protected:

    private:
        int width=960,height=480;
        void DisplayScore(int);
        void DisplayScore();
        sf::RenderWindow window;
};

#endif // SCORE_H
