#ifndef MUSICMENAGER_H
#define MUSICMENAGER_H

class MusicMenager
{
public :
    MusicMenager();
    virtual ~MusicMenager();
    friend class Snake;
    friend class Arcanoid;
    friend class Xionix;


    void  PlayOneShot(std::string);
};

#endif // MUSICMENAGER_H
