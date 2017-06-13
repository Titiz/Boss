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

	sf::Vector2f size;
	sf::RectangleShape rect;
	sf::Vector2f center;
	bool render;
	// Set true if you want it render
};

void RectComponent::set(float width, float height, sf::Color color, Entity e, bool rend = true)
{
	size.x = width;
	size.y = height;
	rect.setPosition(e.getComponent<PositionComponent>().position);
	center.x = rect.getPosition().x + size.x / 2;
	center.y = rect.getPosition().y + size.y / 2;
	rect.setSize(size);
	rect.setFillColor(color);
	render = rend;
}

#endif //RECT_COMPONENT

