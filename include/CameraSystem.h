#pragma once
#include <iostream>
#include <anax/anax.hpp>

#include "Components.h"
#include "Constants.h"
#include "Camera.h"


#ifndef CAMERA_SYSTEM
#define CAMERA_SYSTEM

using namespace anax;

struct CameraSystem : System<Requires<PlayerComponent, PositionComponent, RectComponent>>
{
	Camera camera;
		
	int event;
	
	CameraSystem();
	void	unlock_camera();
	void	update(double deltaTime);
	
private:
	void	process(Entity& e, double deltaTime); 
	void	render(sf::RectangleShape rect) {};
	float	zoom = 0.9f;
};


CameraSystem::CameraSystem() 
{
	CAMERA_POINTER = &camera;
}


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
	ControllerComponent& controllerComp = e.getComponent<ControllerComponent>();

	if (!controllerComp.camera.empty()) {
		event = controllerComp.camera.back();
		controllerComp.movement.pop();
	}

	unlock_camera();

	if (camera.locked) {
		camera.position = rectComponent.center;
		camera.view.setCenter(rectComponent.center.x, rectComponent.center.y);
	}
	else {
		camera.moveWithKeys(deltaTime);
	}
}

void CameraSystem::unlock_camera() 
{
	switch(event) {
		case CAMERA::LOCK_TOGGLE:
			camera.locked = !camera.locked;
			break;
		case CAMERA::ZOOM_IN:
			camera.view.zoom(zoom);
			break;
		case CAMERA::ZOOM_OUT:
			camera.view.zoom(1 / zoom);
			break;
	}
}

#endif // CAMERA_SYSTEM
