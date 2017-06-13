#include <anax/anax.hpp>
#include "Components.h"
#include "GroupManager.h"
#include <vector>
#include "Util.h"

#ifndef ABILITY_COLLISION_SYSTEM
#define ABILITY_COLLISION_SYSTEM

using namespace anax;

// System to take care of collisions between ability squares and all other squares.
struct AbilityCollisionSystem : System<Requires<PositionComponent, RectComponent, InflictAbilityComponent>>
{
	void process(Entity& e, double deltaTime)
	{
		std::cout << ACTIVE_WORLD->getEntityCount() << std::endl;
		Ability &ability = e.getComponent<InflictAbilityComponent>().ability;
		float &time_to_activation = e.getComponent<InflictAbilityComponent>().time_to_activation;
		// FOR NOW ASSUMED THAT PLAYER CASTS ABILITY
		if (time_to_activation <= 0) {
			for(std::vector<Entity>::iterator it = Groups[ENEMY].begin(); it != Groups[ENEMY].end(); ++it) { //Go through every enemy
				if (IsCollided(e.getComponent<RectComponent>().rect, it->getComponent<RectComponent>().rect)) { // Check for collision with every square
					if (!it->hasComponent<ABAComponent>()) { // If we have a match, we make sure the entity is inflicted by ability
						it->addComponent<ABAComponent>();
						it->activate();
					}
					it->getComponent<ABAComponent>().abilities.push(ability);
				}
			}
			std::cout << "DELETING: " << e.getId() << std::endl;
			e.deactivate();
			e.kill();
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
	}
};

# endif //ABILITY_COLLISION_SYSTEM