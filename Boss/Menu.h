#pragma once
#include <StateStruct.h>



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

	Entity player = world.createEntity();
	Entity Boss = world.createEntity();

};

MenuState::MenuState()
{
	world.addSystem(play);
	world.addSystem(movsystem);
	world.addSystem(cameraSystem);
	world.addSystem(rend);

	player.addComponent<PositionComponent>();
	player.addComponent<VelocityComponent>();
	player.addComponent<PlayerComponent>();
	player.addComponent<RectComponent>().set(50, 50, sf::Color::Green);
	player.activate();

	Boss.addComponent<PositionComponent>();
	Boss.addComponent<VelocityComponent>();
	Boss.addComponent<RectComponent>().set(200, 200, sf::Color::Red);
	Boss.activate();


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
	sf::Vector2f pos = player.getComponent<PositionComponent>().position;
	sf::Time deltaTime = deltaClock.restart();


	//Other Systems
	play.update(deltaTime.asSeconds());
	movsystem.update(deltaTime.asSeconds());
	cameraSystem.update(deltaTime.asSeconds());
	

	//render Systems
	rend.update(deltaTime.asSeconds());

	world.refresh();
}

void MenuState::render() {
	
}

void MenuState::processEvents() {

}
