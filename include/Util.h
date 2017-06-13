#include <anax/anax.hpp>
#include "Components.h"
#include <SFML/Graphics.hpp>


#ifndef UTIL
#define UTIL

bool IsCollided(sf::RectangleShape &rect1, sf::RectangleShape &rect2) {
	if (rect1.getGlobalBounds().intersects(rect2.getGlobalBounds())){
		return true;
	}
	return false;
}

#endif //UTIL