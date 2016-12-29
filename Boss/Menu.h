#pragma once
#include <StateStruct.h>


class MenuState: public State {
public:
	MenuState();
	int	run();
private:
	void	processEvents();
	void	update();
	void	render();

	sf::CircleShape mPlayer;
	anax::World world;
	sf::Clock deltaClock;
	MovementSystem movsystem;
	PlayerSystem play;
	Entity player = world.createEntity();

};

MenuState::MenuState()
	: mPlayer()
{
	mPlayer.setRadius(40.f);
	mPlayer.setFillColor(sf::Color::Green);


	world.addSystem(play);
	world.addSystem(movsystem);

	player.addComponent<PositionComponent>();
	player.addComponent<VelocityComponent>();
	player.addComponent<PlayerComponent>();
	player.activate();
}

int MenuState::run() {
	update();
	render();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		return 1;
	}
	return 0;
	
}

void MenuState::update() {
	sf::Vector2f pos = player.getComponent<PositionComponent>().position;
	sf::Time deltaTime = deltaClock.restart();

	movsystem.update(deltaTime.asSeconds());
	play.update(deltaTime.asSeconds());

	mPlayer.setOrigin(pos.x, pos.y);
	world.refresh();
}

void MenuState::render() {
	WINDOW.clear();
	WINDOW.draw(mPlayer);
	WINDOW.display();
}

void MenuState::processEvents() {

}
