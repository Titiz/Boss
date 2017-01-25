#pragma once
#include <iostream>
#include <anax/anax.hpp>
#include <SFML/Graphics.hpp>
#include <Components.h>
#include <Constants.h>

#ifndef CONT_SYSTEM
#define CONT_SYSTEM

using namespace anax;

struct ControllerSystem : System<Requires<ControllerComponent>>
{
	ControllerSystem();
	sf::Event event;
	void update(double deltaTime);

private:
	void process(Entity& e, double deltaTime);  
};

ControllerSystem::ControllerSystem() {}

void ControllerSystem::process(Entity& e, double deltaTime)
{
  ControllerComponent controllerComp = e.getComponent<ControllerComponent>();
  while (WINDOW.pollEvent(event)) {
     switch (event.key.code) {
		case sf::Keyboard::W:
			controllerComp.movement.push(MOVEMENT::MOVE_UP);
			break;
		case sf::Keyboard::S:
			controllerComp.movement.push(MOVEMENT::MOVE_DOWN);
			break;
		case sf::Keyboard::A:
			controllerComp.movement.push(MOVEMENT::MOVE_LEFT);
			break;
		case sf::Keyboard::D:
			controllerComp.movement.push(MOVEMENT::MOVE_RIGHT);
			break;
		case sf::Keyboard::C:
			controllerComp.camera.push(CAMERA::LOCK_TOGGLE);
			break;
		case sf::Keyboard::P:
			controllerComp.camera.push(CAMERA::ZOOM_IN);
			break;
		case sf::Keyboard::O:
			controllerComp.camera.push(ZOOM_OUT);
			break;
		}
	}
}

void ControllerSystem::update(double deltaTime) {}

#endif //CONT_SYSTEM
