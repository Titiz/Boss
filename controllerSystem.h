#include <anax/anax.hpp>
#include <Components.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef CONT_SYSTEM
#define CONT_SYSTEM

using namespace anax;

struct ControllerSystem : System<Requires<ControllerComponent>>
{
	void process(Entity& e, double deltaTime)
	{

	}

	void update(double deltaTime)
	{

	}	
};

#endif
