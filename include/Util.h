#include <anax/anax.hpp>
#include "Components.h"
#include <SFML/Graphics.hpp>


#ifndef UTIL
#define UTIL

bool IsCollided(sf::RectangleShape &rect1, sf::RectangleShape &rect2) {
	if (rect1.getPosition().x < rect2.getPosition().x + rect2.getSize().x &&
		rect1.getPosition().x + rect1.getSize().x > rect2.getPosition().x &&
		rect1.getPosition().y < rect2.getPosition().y + rect2.getSize().y &&
		rect1.getSize().y + rect1.getPosition().y > rect2.getPosition().y) {
		return true;
	}
	return false;
}

#endif //UTIL