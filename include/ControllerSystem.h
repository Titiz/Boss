#pragma once
#include <anax/anax.hpp>
#include <SFML/Graphics.hpp>
#include <Components.h>
#include <Constants.h>
#include <iostream>

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
  ControllerComponent& controllerComp = e.getComponent<ControllerComponent>();
  while (WINDOW.pollEvent(event)) {
	  if (event.type == sf::Event::KeyPressed) {
		  switch (event.key.code) {
		  case sf::Keyboard::C:
			  controllerComp.camera.push(CAMERA::LOCK_TOGGLE);
			  break;
		  case sf::Keyboard::P:
			  controllerComp.camera.push(CAMERA::ZOOM_IN);
			  break;
		  case sf::Keyboard::O:
			  controllerComp.camera.push(CAMERA::ZOOM_OUT);
			  break;
		  }

	  }

	  if (event.type == sf::Event::MouseButtonPressed) {
		  switch (event.mouseButton.button) {
		  case sf::Mouse::Left:
			  controllerComp.attacks.push(ATTACKS::SWING);
			  break;
		  case sf::Mouse::Right:
			  controllerComp.attacks.push(ATTACKS::DASH);
			  break;

		  }

	  }
  }

  // Movement
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
	  controllerComp.movement.push(MOVEMENT::MOVE_UP);
  } 

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
	  controllerComp.movement.push(MOVEMENT::MOVE_DOWN);
  } 
  else {
	  controllerComp.movement.push(MOVEMENT::NULL_MOVE_Y);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
	  controllerComp.movement.push(MOVEMENT::MOVE_LEFT);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
	  controllerComp.movement.push(MOVEMENT::MOVE_RIGHT);
  } 
  else {
	  controllerComp.movement.push(MOVEMENT::NULL_MOVE_X);
  }




}

void ControllerSystem::update(double deltaTime) {
	{
		auto entities = getEntities();

		for (auto i : entities)
		{
			process(i, deltaTime);
		}
	};
}

#endif //CONT_SYSTEM
