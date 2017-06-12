#pragma once
#include <anax\anax.hpp>
#include <map>
#include <vector>
#include <Constants.h>

using namespace anax;



struct Worldc : public World {
	std::map<GROUPS, std::vector<int>> groups;
};