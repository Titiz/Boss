#pragma once
#include <StateStruct.h>
#include <Constants.h>

class FightingState : public State {
public:
			FightingState();
	void 	run();
private:
	void	processEvents();
	void	update();
	void	render();

	sf::CircleShape mPlayer;
	anax::World world;
	sf::Clock deltaClock;

	MovementSystem movsystem;
	PlayerSystem play;
	ControllerSystem controllerSys;

	Entity player = world.createEntity();

};

FightingState::FightingState() : mPlayer() 
{
	mPlayer.setRadius(40.f);
	mPlayer.setFillColor(sf::Color::Red);

	world.addSystem(controllerSys);
	world.addSystem(play);
	world.addSystem(movsystem);

	player.addComponent<ControllerComponent>();
	player.addComponent<PositionComponent>();
	player.addComponent<VelocityComponent>();
	player.addComponent<PlayerComponent>();
	player.activate();
};

void FightingState::run() 
{
	update();
	render();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		STATE_ID = STATE_IDS::MENU;
	}
	else {
		STATE_ID = STATE_IDS::FIGHTING;
	}
};

void FightingState::update() {
	sf::Vector2f pos = player.getComponent<PositionComponent>().position;
	sf::Time deltaTime = deltaClock.restart();

	movsystem.update(deltaTime.asSeconds());
	play.update(deltaTime.asSeconds());

	mPlayer.setOrigin(pos.x, pos.y);
	world.refresh();
	
};

void FightingState::render() {
	WINDOW.clear();
	WINDOW.draw(mPlayer);
	WINDOW.display();
};

void FightingState::processEvents() {};