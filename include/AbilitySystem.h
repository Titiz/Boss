#pragma once

#include <Components.h>
#include <Constants.h>
#include <queue>
#include "Ability.h"
#include <map>
#include <vector>
#include "MouseUtil.h"
#include <iostream>

#ifndef ABILITY_SYSTEM
#define ABILITY_SYSTEM

// This system already knows which entities are affected by what ability
// It makes sure that those entities get the effect of that ability.
// Thus is does not actually take care of animation or any of that.

struct AbilitySystem : System<Requires<ABAComponent>> { 
	void process(Entity& e, double deltaTime)
	{
		
		while (!e.getComponent<ABAComponent>().abilities.empty()) {
			Ability currentAbility = e.getComponent<ABAComponent>().abilities.front();
			e.getComponent<ABAComponent>().abilities.pop();
			std::map<Effects, std::vector<float>>::iterator iter;
			// Do what the ability's effects are.

			// We go through every effect listed in the ability
			// And do whatever we need to depending on the requirements
			for (iter = currentAbility.abilityMap.begin(); iter != currentAbility.abilityMap.end(); iter++) 
			{
				Effects effectName = iter->first;
				std::vector<float> vec = iter->second;
				
				switch (effectName) {

				case INSTANT_DAMAGE: {
					HealthComponent& healthComp = e.getComponent<HealthComponent>();
					healthComp.health -= vec.at(0);
					std::cout << healthComp.health;
					break;
				}

				case KNOCKFORWARD:{
						VelocityComponent& velocityComp = e.getComponent<VelocityComponent>();
						VelocityVector vel(vec.at(0), vec.at(1), true, 10);
						velocityComp.velocities.push_back(vel);
						break;
					}
				}
			
			}
		}
		e.removeComponent<ABAComponent>();  // Once all the effects are processed we remove the component
		e.activate();
	}


	void update(double deltaTime)
	{
		auto entities = getEntities();

		for (auto i : entities)
		{
			process(i, deltaTime);
		}
	};
};












#endif // ABILITY_SYSTEM