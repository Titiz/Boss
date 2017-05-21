#pragma once

#include <anax/anax.hpp>
#include <SFML/Graphics.hpp>
#include "Ability.h"
#include <queue>

#ifndef ABA_COMPONENT
#define ABA_COMPONENT

using namespace anax;

struct ABAComponent : Component
{
	std::queue<Ability> abilities;  // store by what abilities the entity is affected by.
};

#endif //ABA_COMPONENT

