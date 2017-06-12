#include <anax/anax.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <vector>
#include "Constants.h"

using namespace anax;


#ifndef ABILITY_COMPONENT
#define ABILITY_COMPONENT


class Ability
{
public:
	Entity caster; // We want to know the source of the caster.
	AFFECTS affects;
	std::map<Effects, std::vector<float>> abilityMap;   // the vector will have a bunch of settings for that ability type. Say bleed will have duration and dps.
	std::vector<sf::RectangleShape> rectangles; // If the ability uses an area of effect, it will have certain rectangles that it affects. We will specify size and coordinates away from caster.
	int damage_to_target = 0;  
	float cooldown;
	int cost;
};

#endif //ABILITY_COMPONENT