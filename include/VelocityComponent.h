#include <anax/anax.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <VelocityVector.h>

using namespace anax;

#ifndef VELOCITY_COMPONENT
#define VELOCITY_COMPONENT

struct VelocityComponent : Component
{
	sf::Vector2f velocity;
	sf::Vector2f max_velocity;
	std::vector<VelocityVector> velocities;

	void set_max_velocity(float vx, float vy) {
		max_velocity.x = vx;
		max_velocity.y = vy;
	}

	void set_velocity(float vx, float vy) {
		velocity.x = vx;
		velocity.y = vy;
	}

	void add_velocity(float vx, float vy) {
	velocity.x += vx;
	velocity.y += vy;
	}
};

#endif // VELOCITY_COMPONENT