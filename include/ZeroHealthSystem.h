#pragma once
#include <anax/anax.hpp>
#include <Components.h>
#include <Constants.h>
#include <iostream>
#include <Systems.h>

using namespace anax;

#ifndef ZERO_HEALTH_SYSTEM
#define ZERO_HEALTH_SYSTEM



struct ZeroHealthSystem : System<Requires<HealthComponent>>
{

	void process(Entity& e, double deltaTime)
	{
		auto healthComp = e.getComponent<HealthComponent>();
		if (healthComp.health <= 0) {
			e.deactivate();
			e.kill();
		}

		

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

#endif // ZERO_HEALTH_SYSTEM