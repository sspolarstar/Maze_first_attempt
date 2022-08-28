#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "Global.hpp"



//all I really need a collider to do is to check and make sure that the elements don't enter the map grid out of good movement local.
bool map_collision(short i_x, short i_y,const std::array<std::array< Cell, MAP_HEIGHT>, MAP_WIDTH>&mapRef);

