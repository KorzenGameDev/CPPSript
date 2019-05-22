#ifndef SCORE_H
#define SCORE_H


class Score
{
    public:
        Score();
        virtual ~Score();
        friend class Snake;
        friend class Arcanoid;
        friend class Xionix;
    protected:

    private:
        int width=960,height=480;
        void DisplayScore(int);
        void DisplayScore();
        sf::RenderWindow window;
};

#endif // SCORE_H
