#pragma once
#include <SFML/Graphics.hpp>
#include <anax/anax.hpp>
#include <Systems.h>
#include <Constants.h>

class State {

public:
	virtual			~State() {};
	virtual void	run() = 0;

private:
	virtual void	processEvents() = 0;
	virtual void	update() = 0;
	virtual void	render() = 0;
};