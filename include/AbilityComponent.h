#pragma once

#include <queue>
#include <vector>
#include <anax/anax.hpp>

#ifndef ABILITY_COMPONENT
#define ABILITY_COMPONENT

using namespace anax;

struct AbilityComponent : Component
{
	std::vector<int> equipped_abilities;
	std::queue<int> casted_abilities;
};

#endif //ABILITY_COMPONENT