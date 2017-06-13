#pragma once

#include <Components.h>
#include <Constants.h>
#include <queue>
#include "Components.h"
#include "Ability.h"
#include <map>
#include <vector>
#include <math.h>

// returns the magnitude of the vector in the given direction from the location of the entity to the mouse location
sf::Vector2f get_magnitude_in_mouse_direction(float size, Entity& e) { 
	PositionComponent& posComp = e.getComponent<PositionComponent>();
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(WINDOW);
	sf::Vector2f mouse_world_pos;
	mouse_world_pos = WINDOW.mapPixelToCoords(mouse_pos);
	sf::Vector2f difference_vector;
	difference_vector.x = mouse_world_pos.x - posComp.position.x;
	difference_vector.y = mouse_world_pos.y - posComp.position.y;
	float magnitude = sqrt(difference_vector.x * difference_vector.x + difference_vector.y * difference_vector.y);
	float x = size * difference_vector.x / magnitude;
	float y = size * difference_vector.y / magnitude;
	return sf::Vector2f(x, y);
}

// returns angle between the entity's position to the mouse cursor.
double get_angle_in_mouse_direction(Entity &e) {
	PositionComponent& posComp = e.getComponent<PositionComponent>();
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(WINDOW);
	sf::Vector2f mouse_world_pos;
	mouse_world_pos = WINDOW.mapPixelToCoords(mouse_pos);
	sf::Vector2f difference_vector;
	difference_vector.x = mouse_world_pos.x - posComp.position.x;
	difference_vector.y = mouse_world_pos.y - posComp.position.y;
	return atan(difference_vector.y / difference_vector.x) * 180 / 3.14159265;
}