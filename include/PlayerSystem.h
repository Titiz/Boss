#include <anax/anax.hpp>
#include <Components.h>
#include <Constants.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef PLAYER_SYSTEM
#define PLAYER_SYSTEM

using namespace anax;

struct PlayerSystem : System<Requires<PositionComponent, VelocityComponent, PlayerComponent>>
{

	int current_event = 0;

	void process(Entity& e, double deltaTime)
	{
		//Component retrieval
		
		ControllerComponent& controllerComp = e.getComponent<ControllerComponent>();

		// translate the object


		
		while (!controllerComp.movement.empty()) {
			current_event = controllerComp.movement.front();
			controllerComp.movement.pop();
			set_velocity(e);
		}
		

	}


	void set_velocity(Entity& e) {
		VelocityComponent& velocityComp = e.getComponent<VelocityComponent>();
		AccelerationComponent& accComp = e.getComponent<AccelerationComponent>();

		float v = 50.0f;
		sf::Vector2f velocity = velocityComp.velocity;

		if (current_event == MOVEMENT::MOVE_LEFT) {
			velocityComp.set_velocity(-v, velocity.y);

		}
		else if (current_event == MOVEMENT::MOVE_RIGHT) {
			velocityComp.set_velocity(v, velocity.y);
		}
		else if (current_event == MOVEMENT::NULL_MOVE_X) {
			velocityComp.set_velocity(0, velocity.y);
		}

		velocity = velocityComp.velocity;

		if (current_event == MOVEMENT::MOVE_UP) {
			velocityComp.set_velocity(velocity.x, -v);
		}
		else if (current_event == MOVEMENT::MOVE_DOWN) {
			velocityComp.set_velocity(velocity.x, v);
		}
		else if (current_event == MOVEMENT::NULL_MOVE_Y) {
			velocityComp.set_velocity(velocity.x, 0);
			
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
#endif // PLAYER_SYSTEM