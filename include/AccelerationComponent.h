#include <anax/anax.hpp>
#include <SFML/System/Vector2.hpp>

using namespace anax;

#ifndef ACCELERATION_COMPONENT
#define ACCELERATION_COMPONENT

struct AccelerationComponent : Component
{

	sf::Vector2f acceleration;


	void set_acceleration(float ax, float ay) {
		acceleration.x = ax;
		acceleration.y = ay;
	}

	void add_acceleration(float ax, float ay) {
		acceleration.x += ax;
		acceleration.y += ay;
	}
};

#endif // ACCELERATION_COMPONENT