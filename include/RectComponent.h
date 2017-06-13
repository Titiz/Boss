#pragma once

#include <anax/anax.hpp>
#include <SFML/Graphics.hpp>


#ifndef RECT_COMPONENT
#define RECT_COMPONENT

using namespace anax;

struct RectComponent : Component
{
public:
	void set(float width, float height, sf::Color color, Entity e, bool rend = true);
	void setRotation(float angle); 

	sf::Vector2f size;
	sf::RectangleShape rect;
	sf::Vector2f center;
	bool render;
	// Set true if you want it render
};

void RectComponent::set(float width, float height, sf::Color color, Entity e, bool rend)
{
	size.x = width;
	size.y = height;
	rect.setPosition(e.getComponent<PositionComponent>().position);
	rect.setOrigin(size.x/2, size.y/2); // set origin from (0,0) to the center of rectangle
	center.x = rect.getPosition().x + size.x/2;
	center.y = rect.getPosition().y + size.y/2;
	rect.setSize(size);
	rect.setFillColor(color);
	render = rend;
}

void RectComponent::setRotation(float angle) {
	rect.setRotation(angle);
}



#endif //RECT_COMPONENT

