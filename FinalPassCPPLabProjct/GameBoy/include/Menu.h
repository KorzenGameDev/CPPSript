#ifndef MENU_H
#define MENU_H
/**@brief menu glowne projektu  */
class Menu
{

public:
    /**@brief konstruktor klasy menu */
	Menu();
	/**@brief destruktor klasy menu */
	~Menu();
	/**@brief zaladowuje wszystkie glowne funkcje - klasy menu */
    void Setup();
private:
    /**@brief odpowiada za rysowanie okna menu glownego i opcji wyboru*/
    void Draw();
    /**@brief ustawia i wyswietla opcje menu
    *
    *@param[in] tekstura snake przycisku
    *@param[in] tekstura xionix przycisku
    *@param[in] tekstura arkanoid z przycisku
    *@param[in] tekstura exit z przycisku
    */
	void DisplayOptions(sf::Texture&, sf::Texture&, sf::Texture&, sf::Texture&);
	/**@brief inkrementuje wartosc selectedItemIndex */
	void MoveUp();
	/**@brief dekrementuje wartosc selectedItemIndex */
	void MoveDown();

	sf::RenderWindow window;
	sf::Texture t1,t2,t3,t4;
	int width=960,height=480;
	int GetPressedItem() { return selectedItemIndex; }
    const static int MAX_NUMBER_OF_ITEMS=4;
	int selectedItemIndex=0;
};

#endif // MENU_H
