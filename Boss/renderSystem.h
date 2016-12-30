#pragma once
#include <anax/anax.hpp>
#include <Components.h>
#include <iostream>
using namespace anax;

#ifndef MOVEMENT_SYSTEM
#define MOVEMENT_SYSTEM



struct MovementSystem : System<Requires<PositionComponent,  >>
{
	void process(Entity& e, double deltaTime)
	{
		PositionComponent& positionComp = e.getComponent<PositionComponent>();
		VelocityComponent& velocityComp = e.getComponent<VelocityComponent>();
		// translate the object
		std::cout << velocityComp.velocity.x;
		positionComp.position.x += velocityComp.velocity.x * deltaTime;
		positionComp.position.y += velocityComp.velocity.y * deltaTime;
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
#endif // MOVEMENT_SYSTEM