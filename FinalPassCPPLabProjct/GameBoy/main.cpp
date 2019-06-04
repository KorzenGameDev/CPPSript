#include "Library.h"

int main()
{
    sf::Music bgMusic;
    bgMusic.openFromFile("music/bgMusic.wav");
    bgMusic.setLoop(true);
    bgMusic.play();

    Menu menu;
    menu.Setup();
}
