#include "Library.h"

MusicMenager::MusicMenager()
{

}
MusicMenager::~MusicMenager()
{

}

void MusicMenager::PlayOneShot(std::string str)
{
    std::cout<<"im";
    sf::Music music;
    music.openFromFile("music/"+str+".wav");
    music.play();
}
