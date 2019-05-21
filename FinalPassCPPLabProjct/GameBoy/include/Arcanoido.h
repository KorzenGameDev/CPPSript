#ifndef ARCANOIDO_H
#define ARCANOIDO_H

class Arcanoido
{

public:
	Arcanoido();
	~Arcanoido();

private:
    void Setup();
    void Draw(sf::RenderWindow &window, int ,int );

	sf::RenderWindow window;
};

#endif // ARCANOIDO_H
