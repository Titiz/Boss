#pragma once
#include <SFML/Graphics.hpp>
#include <Camera.h>


//Global Variables
int STATE_ID = 0;
enum STATE_IDS { MENU = 0, FIGHTING = 1 };
sf::Vector2f SIZE(800, 600);
sf::RenderWindow WINDOW(sf::VideoMode(SIZE.x, SIZE.y, 32), "Bosses");
sf::RenderWindow* WINDOW_POINTER = &WINDOW;
Camera *CAMERA_POINTER;


enum MOVEMENT {
  MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, ROLL, SPRINT
};

enum ATTACKS {
  DASH, SWING
};

enum CAMERA {
  ZOOM_IN, ZOOM_OUT, LOCK_TOGGLE
}

