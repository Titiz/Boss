#pragma once

#include <anax/anax.hpp>
#include <Components.h>
#include <Constants.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef ACCELERATION_SYSTEM
#define ACCELERATION_SYSTEM

struct AccelerationSystem : System<Requires<VelocityComponent, AccelerationComponent>>
{
	void update(double deltaTime);
	AccelerationSystem();
private:
	void process(Entity& e, double deltaTime);
};

AccelerationSystem::AccelerationSystem() {}

void AccelerationSystem::update(double deltaTime) {

	{
		auto entities = getEntities();


		for (auto i : entities)
		{
			process(i, deltaTime);
		}
	};
}

void AccelerationSystem::process(Entity& e, double deltaTime) {
	AccelerationComponent& accelerationComp = e.getComponent<AccelerationComponent>();
	VelocityComponent& velocityComp = e.getComponent<VelocityComponent>();


	std::cout << velocityComp.velocity.x;

	std::cout << "YH" << accelerationComp.acceleration.y;

	if (accelerationComp.acceleration.x > 0) {
		if (velocityComp.velocity.x > velocityComp.max_velocity.x) {
			velocityComp.velocity.x = velocityComp.max_velocity.x;
		}
		else {
			velocityComp.add_velocity(accelerationComp.acceleration.x, 0);

		}
	}
	else if (accelerationComp.acceleration.x< 0) {
		if (velocityComp.velocity.x < -velocityComp.max_velocity.x) {
			velocityComp.velocity.x = -velocityComp.max_velocity.x;
		}
		else {
			velocityComp.add_velocity(accelerationComp.acceleration.x, 0);
		}
	}



	if (accelerationComp.acceleration.y < 0) {
		if (velocityComp.velocity.y < -velocityComp.max_velocity.y) {
			velocityComp.velocity.y = -velocityComp.max_velocity.y;
		}
		else {
			velocityComp.add_velocity(0, accelerationComp.acceleration.y);

		}
	}
	else if (accelerationComp.acceleration.y > 0) {
		if (velocityComp.velocity.y > velocityComp.max_velocity.y) {
			velocityComp.velocity.y = velocityComp.max_velocity.y;
		}
		else {
			velocityComp.add_velocity(0, accelerationComp.acceleration.y);
		}
	}
}

#endif //ACCELERATION_SYSTEM