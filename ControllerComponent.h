#pragma once

#include <queue>
#include <anax/anax.hpp>

#ifndef CONT_COMPONENT
#define CONT_COMPONENT

using namespace anax;

struct ControllerComponent : Component
{
	std::queue<int> movement;
	std::queue<int> attacks;
};

#endif //CONT_COMPONENT
