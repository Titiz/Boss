#pragma once
#include <anax/anax.hpp>

#ifndef HEALTH_COMPONENT
#define HEALTH_COMPONENT

using namespace anax;

struct HealthComponent : Component
{
	int health = 0;
};

#endif //HEALTH_COMPONENT
