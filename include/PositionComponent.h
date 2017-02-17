#include <anax/anax.hpp>
#include <SFML/System/Vector2.hpp>

#ifndef POSITION_COMPONENT
#define POSITION_COMPONENT

using namespace anax;

struct PositionComponent : Component
{
	sf::Vector2f position;
};

#endif //POSITION_COMPONENT