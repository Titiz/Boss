#pragma once
# include <SFML\Graphics.hpp>




//Global Variables
int STATE_ID = 0;
enum STATE_IDS { MENU = 0, FIGHTING = 1 };
sf::Vector2f SIZE(800, 600);
sf::RenderWindow WINDOW(sf::VideoMode(SIZE.x, SIZE.y, 32), "SFML Demo 3");

