#include <anax/anax.hpp>
#include <Components.h>
#include <Constants.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <VelocityVector.h>
#include <SFML/System/Vector2.hpp>
#include <math.h>     

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
			attack(e);
		}
		

	}

	void attack(Entity& e) {
		VelocityComponent& velocityComp = e.getComponent<VelocityComponent>();
		PositionComponent& posComp = e.getComponent<PositionComponent>();
		float speed = 800;
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(WINDOW);
		sf::Vector2f mouse_world_pos;
		mouse_world_pos = WINDOW.mapPixelToCoords(mouse_pos);
		sf::Vector2f difference_vector;
		difference_vector.x = mouse_world_pos.x - posComp.position.x;
		difference_vector.y = mouse_world_pos.y - posComp.position.y;
		float magnitude = sqrt(difference_vector.x * difference_vector.x + difference_vector.y * difference_vector.y);
		float x = speed * difference_vector.x / magnitude;
		float y = speed * difference_vector.y / magnitude;

		
		if (current_event == ATTACKS::DASH) {
			VelocityVector vel(x, y, true, 10);
			velocityComp.velocities.push_back(vel);
		}


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