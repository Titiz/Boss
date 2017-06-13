#pragma once
#include <StateStruct.h>
#include <Systems.h>
#include <vector>
#include "Constants.h"


class MenuState: public State {
public:
			MenuState();
	void	run();
private:
	void	processEvents();
	void	update();
	void	render();

	anax::World world;
	

	sf::Clock deltaClock;

	MovementSystem movsystem;
	PlayerSystem play;
	RenderSystem rend;
	CameraSystem cameraSystem;
	ControllerSystem contSystem;
	AbilitySystem abilitySystem;
	AbilityCollisionSystem abilColSys;
	

	Entity player = world.createEntity();
	Entity Boss = world.createEntity();

};

MenuState::MenuState()
{
	ACTIVE_WORLD = &world;

	world.addSystem(play);
	world.addSystem(movsystem);
	world.addSystem(cameraSystem);
	world.addSystem(rend);
	world.addSystem(contSystem);
	world.addSystem(abilitySystem);
	world.addSystem(abilColSys);


	player.addComponent<PositionComponent>();
	player.addComponent<VelocityComponent>().set_max_velocity(50, 50);
	player.addComponent<PlayerComponent>();
	player.addComponent<RectComponent>().set(50, 50, sf::Color::Green, player);
	player.addComponent<ControllerComponent>();
	player.activate();

	Boss.addComponent<PositionComponent>();
	Boss.addComponent<VelocityComponent>();
	Boss.addComponent<RectComponent>().set(200, 200, sf::Color::Red, Boss);
	Boss.addComponent<HealthComponent>().health = 100;
	Boss.activate();
	Groups[ENEMY].push_back(Boss);


}

void MenuState::run() {
	update();
	render();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		STATE_ID = STATE_IDS::FIGHTING;
	}
	else {
		STATE_ID = STATE_IDS::MENU;
	}
}

void MenuState::update() {
	std::vector<Entity> enemies;
	sf::Time deltaTime = deltaClock.restart();

	
	//Other Systems
	contSystem.update(deltaTime.asSeconds());
	play.update(deltaTime.asSeconds());
	movsystem.update(deltaTime.asSeconds());
	cameraSystem.update(deltaTime.asSeconds());
	abilitySystem.update(deltaTime.asSeconds());
	abilColSys.update(deltaTime.asSeconds());
	
	

	//render Systems
	rend.update(deltaTime.asSeconds());

	world.refresh();
}

void MenuState::render() {
	
}

void MenuState::processEvents() {

}
