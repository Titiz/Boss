#pragma once

#include <anax/anax.hpp>
#include <SFML/Graphics.hpp>


#ifndef RECT_COMPONENT
#define RECT_COMPONENT

using namespace anax;

struct RectComponent : Component
{
public:
	RectComponent(float width, float height, sf::Color color);

	sf::Vector2f size;
	sf::RectangleShape rect;
	sf::Color color;
	bool render = true;

	
};


RectComponent::RectComponent(float width, float height, sf::Color col)
{
	size.x = width;
	size.y = height;
	color = col;
}

#endif //RECT_COMPONENT

