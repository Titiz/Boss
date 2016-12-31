#pragma once
# include <SFML\Graphics.hpp>




//Global Variables
int STATE_ID = 0;
enum STATE_IDS { MENU = 0, FIGHTING = 1 };
sf::View VIEW;
sf::RenderWindow WINDOW(sf::VideoMode(640, 480, 32), "SFML Demo 3");