#ifndef MENU_H
#define MENU_H

class Menu
{

public:
	Menu();
	~Menu();
    void Setup();
private:
    void Draw(sf::RenderWindow &window, int ,int );
	void DisplayOptions(sf::RenderWindow &window, int,int,sf::Texture &t1,sf::Texture &t2,sf::Texture &t3,sf::Texture &t4);
	void MoveUp();
	void MoveDown();

	sf::RenderWindow window;
	int width=960,height=480;
	int GetPressedItem() { return selectedItemIndex; }
    const static int MAX_NUMBER_OF_ITEMS=4;
	int selectedItemIndex=0;
};

#endif // MENU_H
