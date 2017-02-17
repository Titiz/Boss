#pragma once
#include <SFML/Graphics.hpp>
#include <anax/anax.hpp>
#include <States.h>
#include <vector>
#include <Constants.h>

#ifndef GAME
#define GAME

// This is the game class which, for now, serves the 
// purpose of being the whole game

class Game
{
public:
			Game();
	void	run();

private:
	void	processEvents();
	void	update();
	void	render();

private:
	std::vector<State*> States;

	//states
	FightingState fightingState;
	MenuState menuState;

	anax::World world;
	sf::Clock deltaClock;
	
};

Game::Game() 
{
	States.push_back(&menuState);
	States.push_back(&fightingState);
}

void Game::run() {
	while (STATE_ID >= 0) {
		States[STATE_ID]->run();
	}
}

#endif //GAME