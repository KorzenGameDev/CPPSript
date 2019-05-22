#ifndef LIBRARY_H
#define lIBRARY_H

//SFML
 /**@brief podlaczenie biblioteki graficznej */
#include <SFML/Graphics.hpp>

//C++
 /**@brief biblioteka standardowa*/
#include <iostream>
 /**@brief biblioteka ciagu znakow*/
#include <string>
 /**@brief biblioteka czasu */
#include <time.h>

//OWN
 /**@brief plik naglowkowy menu*/
#include "Menu.h"
/**@brief plik naglowkowy snake*/
#include "Snake.h"
/**@brief plik naglowkowy score*/
#include "Score.h"
/**@brief plik naglowkowy arcanoid*/
#include "Arcanoid.h"
/**@brief plik naglowkowy xionix*/
#include "Xionix.h"

//NAMESPACE
/**@brief uzcyie przestrzeni nazw std*/
using namespace std;
/**@brief uzycie przestrzeni nazw sfml*/
using namespace sf;

#endif // SNAKE_H
