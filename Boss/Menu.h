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

	sf::CircleShape mPlayer;
	anax::World world;
	sf::Clock deltaClock;

	MovementSystem movsystem;
	PlayerSystem play;
	RenderSystem rend;

	Entity player = world.createEntity();

};

MenuState::MenuState()
	: mPlayer()
{
	mPlayer.setRadius(40.f);
	mPlayer.setFillColor(sf::Color::Green);


	world.addSystem(play);
	world.addSystem(movsystem);
	world.addSystem(rend);

	player.addComponent<PositionComponent>();
	player.addComponent<VelocityComponent>();
	player.addComponent<PlayerComponent>();
	player.addComponent<RectComponent>().set(200, 200, sf::Color::Red);
	player.activate();
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

	movsystem.update(deltaTime.asSeconds());
	play.update(deltaTime.asSeconds());
	rend.update(deltaTime.asSeconds());

	mPlayer.setOrigin(pos.x, pos.y);
	world.refresh();
}

void MenuState::render() {
	
}

void MenuState::processEvents() {

}
