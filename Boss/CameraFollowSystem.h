#pragma once
#pragma once
#include <anax/anax.hpp>
#include <Components.h>
#include <Constants.h>
#include <iostream>
using namespace anax;

#ifndef CAMERA_SYSTEM
#define CAMERA_SYSTEM



struct CameraSystem : System<Requires<PlayerComponent, PositionComponent>>
{
	void process(Entity& e, double deltaTime)
	{
		RectComponent& rectComponent = e.getComponent<RectComponent>();
		PositionComponent& positionComp = e.getComponent<PositionComponent>();

		VIEW.setCenter(positionComp.position.x, positionComp.position.y);


	}

	void update(double deltaTime)
	{
		auto entities = getEntities();


		for (auto i : entities)
		{
			process(i, deltaTime);
		}

	}


	void render(sf::RectangleShape rect)
	{
	}

};

#endif // CAMERA_SYSTEM