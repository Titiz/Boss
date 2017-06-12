#pragma once
#include <SFML/Graphics.hpp>
#include <Camera.h>
#include <anax/anax.hpp>


//Global Variables
int STATE_ID = 0;
enum STATE_IDS { MENU = 0, FIGHTING = 1 };
sf::Vector2f SIZE(800, 600);
sf::RenderWindow WINDOW(sf::VideoMode(SIZE.x, SIZE.y, 32), "Bosses");
sf::RenderWindow* WINDOW_POINTER = &WINDOW;
Camera *CAMERA_POINTER;
anax::World *ACTIVE_WORLD;
std::map<int, std::vector<anax::Entity>> Groups;


// Different Enums used in different parts of the game.

enum AFFECTS {
	SELF, AREA
};

enum Effects {
	KNOCKBACK, KNOCKFORWARD, BLEED, INSTANT_DAMAGE
};

enum MOVEMENT {
	NULL_MOVE_X, NULL_MOVE_Y, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, ROLL, SPRINT
};

enum ATTACKS {
	NULL_ATTACK, DASH, SWING
};

enum CAMERA {
	NULL_CAMERA, ZOOM_IN, ZOOM_OUT, LOCK_TOGGLE,
};

enum GROUPS {
	ALLY, ENEMY 
};
