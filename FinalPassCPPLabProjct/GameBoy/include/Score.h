#ifndef SCORE_H
#define SCORE_H


class Score
{
    public:
        Score();
        virtual ~Score();
        friend class Snake;
        friend class Arcanoid;
    protected:

    private:
        int width=960,height=480;
        void DisplayScore(int);
        sf::RenderWindow window;
};

#endif // SCORE_H
