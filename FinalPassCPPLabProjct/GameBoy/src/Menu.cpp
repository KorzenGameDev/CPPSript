#include "Library.h"

Menu::Menu()
{
	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::Setup()
{
    window.create(sf::VideoMode(width , height), "Menu");

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
            {
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					MoveUp();
					break;

				case sf::Keyboard::Down:
					MoveDown();
					break;

				case sf::Keyboard::Return:
                {
					switch (GetPressedItem())
					{
					case 0:
					    {
                            window.close();

                            Snake snake(1,0,0);
                            snake.Setup();
                            break;
					    }
					case 1:
                        {
                            window.close();

                            Xionix xionix(1);
                            xionix.Setup();
                            break;
					    }
                    case 2:
                        {
                            window.close();

                            Arcanoid arcanoid(1,0,0);
                            arcanoid.Setup();
                            break;
					    }
					case 3:
						window.close();
						break;

                    default:
                        break;
					}
                }
                default:
                    break;
				}
				break;
            }
            case sf::Event::Closed:
                window.close();
            break;

            default:
                break;
			}
		}

		window.clear();

		Draw();

		window.display();
	}
}

void Menu::Draw()
{
    sf::Texture t9,t10;
    t10.loadFromFile("images/menu/bg.png");
    sf::Sprite spriteMain(t10);
    spriteMain.setPosition(0,0);
    window.draw(spriteMain);
    t9.loadFromFile("images/menu/nintendo.png");
    sf::Sprite spriteBg(t9);
    spriteBg.setPosition(0,0);
    window.draw(spriteBg);

    sf::Texture t1,t2,t3,t4,t5,t6,t7,t8;
    t1.loadFromFile("images/menu/BtnSnakeIdle.png");
    t2.loadFromFile("images/menu/BtnSnakeUse.png");

    t3.loadFromFile("images/menu/BtnXonixIdle.png");
    t4.loadFromFile("images/menu/BtnXonixUse.png");

    t5.loadFromFile("images/menu/BtnArkadiaIdle.png");
    t6.loadFromFile("images/menu/BtnArkadiaUse.png");

    t7.loadFromFile("images/menu/BtnExitIdle.png");
    t8.loadFromFile("images/menu/BtnExitUse.png");

    switch(selectedItemIndex)
    {
        case 0:
            {
                DisplayOptions(t2,t3,t5,t7);
                break;
            }
        case 1:
            {
                DisplayOptions(t1,t4,t5,t7);
                break;
            }
        case 2:
            {
                DisplayOptions(t1,t3,t6,t7);
                break;
            }
        case 3:
            {
                DisplayOptions(t1,t3,t5,t8);
                break;
            }
        default:
            std::cout<<"Bad menu initatnion"<<std::endl;
            break;
    }



}

void Menu::DisplayOptions(sf::Texture& t1, sf::Texture& t2, sf::Texture& t3, sf::Texture& t4)
{
    sf::Sprite snakeButton(t1);
    sf::Sprite xonixButton(t2);
    sf::Sprite arkadiaButton(t3);
    sf::Sprite exitButton(t4);

    int offset=97;
    snakeButton.setPosition(width/2-offset,75);
    window.draw(snakeButton);
    xonixButton.setPosition(width/2-offset,150);
    window.draw(xonixButton);
    arkadiaButton.setPosition(width/2-offset,225);
    window.draw(arkadiaButton);
    exitButton.setPosition(width/2-offset,325);
    window.draw(exitButton);
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) selectedItemIndex--;
    else if(selectedItemIndex - 1 < 0)  selectedItemIndex=MAX_NUMBER_OF_ITEMS-1;
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)    selectedItemIndex++;
    else if(selectedItemIndex + 1 >=MAX_NUMBER_OF_ITEMS) selectedItemIndex = 0;
}
