#include <anax/anax.hpp>
#include <Components.h>
#include <Constants.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <VelocityVector.h>
#include <SFML/System/Vector2.hpp>
#include <math.h>     
#include "Ability.h"
#include "MouseUtil.h"
#include <vector>

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

		while (!controllerComp.attacks.empty()) {
			current_event = controllerComp.attacks.front();
			controllerComp.attacks.pop();
			do_action(e);
		}
		

	}



	void do_action(Entity& e) {
		Ability ability;
		switch(current_event) {
		case ATTACKS::DASH: {

			std::vector<float> vec;
			sf::Vector2f move_vector = get_magnitude_in_mouse_direction(2000, e);
			vec.push_back(move_vector.x);
			vec.push_back(move_vector.y);
			ability.abilityMap[KNOCKFORWARD] = vec;
			if (!e.hasComponent<ABAComponent>()) {
				e.addComponent<ABAComponent>();
				e.activate();
				}
			}
	
		case ATTACKS::SWING: {
			break;
		}
		}
			e.getComponent<ABAComponent>().abilities.push(ability);
	}



	void set_velocity(Entity& e) {
		VelocityComponent& velocityComp = e.getComponent<VelocityComponent>();

		float v = 50.0f;
		sf::Vector2f velocity;

		if (current_event == MOVEMENT::MOVE_LEFT) {
			velocity.x = -v;

		}
		else if (current_event == MOVEMENT::MOVE_RIGHT) {
			velocity.x = v;
		}
		else if (current_event == MOVEMENT::NULL_MOVE_X) {
			velocity.x = 0;
		}

		

		if (current_event == MOVEMENT::MOVE_UP) {
			velocity.y = -v;
		}
		else if (current_event == MOVEMENT::MOVE_DOWN) {
			velocity.y = v;
		}
		else if (current_event == MOVEMENT::NULL_MOVE_Y) {
			velocity.y = 0;
			
		}
		VelocityVector vel(velocity.x, velocity.y, false, 1);
		velocityComp.velocities.push_back(vel);
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