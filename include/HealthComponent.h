#pragma once
#include <anax/anax.hpp>

#ifndef HEALTH_COMPONENT
#define HEALTH_COMPONENT

using namespace anax;

struct HealthComponent : Component
{
	void set(int health, int group, bool invulnerable = false);

	int health = 1;
	bool invulnerable = false;
	int group = ENEMY;

	
};


void HealthComponent::set(int health, int group, bool invulnerable) {
	this->health = health;
	this->group = group;
	this->invulnerable = invulnerable;
}

#endif //HEALTH_COMPONENT
