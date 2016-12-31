#pragma once
#pragma once
#include <anax/anax.hpp>
#include <Components.h>
#include <Constants.h>
#include <iostream>
#include <Camera.h>
using namespace anax;

#ifndef CAMERA_SYSTEM
#define CAMERA_SYSTEM



struct CameraSystem : System<Requires<PlayerComponent, PositionComponent, RectComponent>>
{

	Camera camera;
	sf::Event event;
	
	void unlock_camera();
	void update(double deltaTime);
	
private:
	void process(Entity& e, double deltaTime); void process(Entity& e, double deltaTime);
	void render(sf::RectangleShape rect) {};

};


void CameraSystem::update(double deltaTime)
{
	auto entities = getEntities();


	for (auto i : entities)
	{
		process(i, deltaTime);
	}

}

void CameraSystem::process(Entity& e, double deltaTime)
{

	sf::View view = camera.view;
	RectComponent& rectComponent = e.getComponent<RectComponent>();
	PositionComponent& positionComp = e.getComponent<PositionComponent>();

	unlock_camera();

	if (camera.locked) {
		camera.position = rectComponent.center;
		camera.view.setCenter(rectComponent.center.x, rectComponent.center.y);
	}
	else {
		camera.moveWithKeys(deltaTime);
	}
	WINDOW.setView(camera.view);

}


void CameraSystem::unlock_camera() {

	while (WINDOW.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) {
			camera.locked = !camera.locked;
		}
	}

}


#endif // CAMERA_SYSTEM