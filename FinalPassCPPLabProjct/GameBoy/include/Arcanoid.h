#ifndef ARCANOID_H
#define ARCANOID_H

class Arcanoid
{

public:
	Arcanoid(int,int,int);
	virtual ~Arcanoid();
    void Setup();
private:
    void Draw(sf::Sprite &sBackground, sf::Sprite &sBall, sf::Sprite &sPaddle , sf::Sprite *block);
    void LoadTextures();
    void PaddleController(sf::Sprite &sPaddle);
    void Positioning(sf::Sprite &sBackground, sf::Sprite &sBall, sf::Sprite &sPaddle , sf::Sprite *block);
    void NextLevel();
    void SpawnBlock(sf::Sprite *block);
    void GetPoint();

    sf::Texture t1,t2,t3,t4;
	sf::RenderWindow window;
	int width=960, height=480;
    float dx=4, dy=4;
	float x=width/2, y=height/2;
	int offsetXmin=170, offsetXmax=800;
	int blockNumber=0;
	int toDestroyMax=0,toDestroy=0;
	int points=0,tempPoints=0;
	int level=0;
};

#endif // ARCANOID_H
