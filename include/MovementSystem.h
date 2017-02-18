#include <anax/anax.hpp>
#include <Components.h>
#include <iostream>
#include <Constants.h>
#include <VelocityVector.h>
using namespace anax;

#ifndef MOVEMENT_SYSTEM
#define MOVEMENT_SYSTEM

struct MovementSystem : System<Requires<PositionComponent, VelocityComponent>>
{
	void process(Entity& e, double deltaTime)
	{
		PositionComponent& positionComp = e.getComponent<PositionComponent>();
		VelocityComponent& velocityComp = e.getComponent<VelocityComponent>();

		velocityComp.velocity.x = 0;
		velocityComp.velocity.y = 0;
		std::vector<VelocityVector> velocities;

		for (int i = 0; i < velocityComp.velocities.size(); i++) {
			velocityComp.velocity.x += velocityComp.velocities.at(i).x;
			velocityComp.velocity.y += velocityComp.velocities.at(i).y;
			velocityComp.velocities.at(i).dissipate();
			if (!velocityComp.velocities.at(i).done) {
				velocities.push_back(velocityComp.velocities.at(i));
			}
			
		}
		velocityComp.velocities = velocities;
		

		// translate the object

		positionComp.position.x += velocityComp.velocity.x * deltaTime;
		positionComp.position.y += velocityComp.velocity.y * deltaTime;

		if (e.hasComponent<RectComponent>()) {
			RectComponent& rectCom = e.getComponent<RectComponent>();
			rectCom.center.x += velocityComp.velocity.x * deltaTime;
			rectCom.center.y += velocityComp.velocity.y * deltaTime;
		}
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