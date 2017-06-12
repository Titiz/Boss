#pragma once
#include <SFML/Graphics.hpp>
#include <anax/anax.hpp>
#include "Components.h"
#include <Constants.h>
#include <Menu.h>
#include <GroupManager.h>


using namespace anax;

Entity createEffectSquare(float time_to_effect, sf::Vector2f size, sf::Vector2f position, Ability ability) {
	Entity e = ACTIVE_WORLD->createEntity();
	e.addComponent<PositionComponent>();
	e.addComponent<RectComponent>();
	e.addComponent<InflictAbilityComponent>();
	e.getComponent<PositionComponent>().position = position;
	e.getComponent<RectComponent>().size = size;
	e.getComponent<InflictAbilityComponent>().ability = ability;
	e.getComponent<InflictAbilityComponent>().time_to_activation = time_to_effect;
	e.activate();
}