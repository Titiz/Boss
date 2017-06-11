#pragma once

#include <anax/anax.hpp>
#include <SFML/Graphics.hpp>
#include "Ability.h"
#include <queue>



using namespace anax;

struct InflictAbilityComponent : Component
{
	Ability ability;
	float time_to_activation;
};



