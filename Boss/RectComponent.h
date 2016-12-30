#pragma once

#include <anax/anax.hpp>
#include <SFML/Graphics.hpp>


#ifndef RECT_COMPONENT
#define RECT_COMPONENT

using namespace anax;

struct RectComponent : Component
{
public:
	void set(float width, float height, sf::Color color);

	sf::Vector2f size;
	sf::RectangleShape rect;
	bool render = true;

	
};


void RectComponent::set(float width, float height, sf::Color color)
{
	size.x = width;
	size.y = height;
	rect.setSize(size);
	rect.setFillColor(color);
}

#endif //RECT_COMPONENT

