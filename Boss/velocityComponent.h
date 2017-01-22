#include <anax/anax.hpp>
#include <SFML/System/Vector2.hpp>

using namespace anax;

#ifndef VELOCITY_COMPONENT
#define VELOCITY_COMPONENT

struct VelocityComponent : Component
{
	sf::Vector2f velocity;

	void set_velocity(float vx, float vy) {
		velocity.x = vx;
		velocity.y = vy;
	}
};

#endif // VELOCITY_COMPONENT