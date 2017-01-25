#pragma once
#include <SFML/Graphics.hpp>
#include <anax/anax.hpp>
#include "Components.h"


class Camera {
public:
	sf::View view;
	bool locked = true;
	sf::Event event;
	sf::Mouse mouse;
	sf::Vector2f position;
	
	void setCameraPos(sf::Vector2f);
	void moveWithKeys(float);
};


void Camera::setCameraPos(sf::Vector2f new_position) {
	position = new_position;
}


void Camera::moveWithKeys(float deltaTime) {
	int velocity = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		position.y -= velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		position.y += velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		position.x -= velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		position.x += velocity;
	}
	view.setCenter(position.x, position.y);
}
