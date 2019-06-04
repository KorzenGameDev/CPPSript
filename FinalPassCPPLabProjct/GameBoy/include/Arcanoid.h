#ifndef ARCANOID_H
#define ARCANOID_H
/**@brief przechowuje funkcje do gry arkanoid */
class Arcanoid
{

public:
    /**@brief konstruktor
    *
    *@param[in] poziom
    *@param[in] liczba punktow
    *@param[in] tymczasowa liczba punktow
     */
	Arcanoid(int,int,int);
	/**@brief destruktor */
	virtual ~Arcanoid();
	/**@brief zaladowuje wszystkie glowne funkcje - klasy menu */
    void Setup();
private:
    /**@brief rysuje okno gry wraz z zawartoscia
    *
    *@param[in] grafika tla
    *@param[in] grafika pilki
    *@param[in] grafika platformy
    *@param[in] grafika klockow
     */
    void Draw(sf::Sprite &sBackground, sf::Sprite &sBall, sf::Sprite &sPaddle , sf::Sprite *block);
    /**@brief zaladowuje tekstury z pliku */
    void LoadTextures();
    /**@brief sterowanie platforma
    *
    *platforma mozna sterowac tylo w lewo i prawo za pomoca przycisku strza³ek na klawiaturze lewo i prawo
    *@param[in] grafika platformy
     */
    void PaddleController(sf::Sprite &sPaddle);
    /**@brief  pozycjonowanie grafiki w oknie
    *
    *@param[in] grafika tla
    *@param[in] grafika pilki
    *@param[in] grafika platformy
    *@param[in] grafika klockow
    */
    void Positioning(sf::Sprite &sBackground, sf::Sprite &sBall, sf::Sprite &sPaddle , sf::Sprite *block);
    /**@brief  nastepny poziom
    *
    *inkrementuje zmienna lewel,przypisuje zmiennej tempPoints wartosc points i zaladowuje nowe tekstury
     */
    void NextLevel();
    /**@brief tworzenie i pozycjonowanie klockow
    *
    *@param[in] grafika klockow
    */
    void SpawnBlock(sf::Sprite *block);
    /**@brief inkrementuje zmienna points*/
    void GetPoint();

    sf::Texture t1,t2,t3,t4,t5;
	sf::RenderWindow window;
	int width=960, height=480;
    float dx=4, dy=4;
	float x=width/2, y=height/2+100;
	int offsetXmin=170, offsetXmax=800;
	int blockNumber=0;
	int toDestroyMax=0,toDestroy=0;
	int level,points,tempPoints;
};

#endif // ARCANOID_H
