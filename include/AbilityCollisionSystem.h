#include <anax/anax.hpp>
#include "Components.h"

#ifndef ABILITY_COLLISION_SYSTEM
#define ABILITY_COLLISION_SYSTEM

using namespace anax;

// System to take care of collisions between ability squares and all other squares.
struct AbilityCollisionSystem : System<Requires<PositionComponent, RectComponent, InflictAbilityComponent>>
{
	void process(Entity& e, double deltaTime)
	{
		Ability &ability = e.getComponent<InflictAbilityComponent>().ability;
		float &time_to_activation = e.getComponent<InflictAbilityComponent>().time_to_activation;

		if (time_to_activation <= 0) {

		}
		else time_to_activation -= deltaTime;
	}

	void update(double deltaTime)
	{
		auto entities = getEntities();
		for (auto i : entities)
		{
			process(i, deltaTime);
		}
		WINDOW.display();
	}
};

# endif //ABILITY_COLLISION_SYSTEM