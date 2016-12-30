#include <anax\anax.hpp>
#include <Components.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef PLAYER_SYSTEM
#define PLAYER_SYSTEM

using namespace anax;


struct PlayerSystem : System<Requires<PositionComponent, VelocityComponent, PlayerComponent>>
{
	void process(Entity& e, double deltaTime)
	{

		VelocityComponent& velocityComp = e.getComponent<VelocityComponent>();
		// translate the object
		float v = 50.0f;
		sf::Vector2f velocity = velocityComp.velocity;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			velocityComp.set_velocity(-v, velocity.y);
		
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			velocityComp.set_velocity(v, velocity.y);
		
		} 
		else {
			velocityComp.set_velocity(0, velocity.y);
			
		}

		velocity = velocityComp.velocity;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			velocityComp.set_velocity(velocity.x , -v);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			velocityComp.set_velocity(velocity.x, v);
		}
		else {
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