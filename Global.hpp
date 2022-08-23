#pragma once

constexpr unsigned char CELL_SIZE = 16;
constexpr unsigned char MAP_HEIGHT = 18;
constexpr unsigned char TEXT_HEIGHT = 16;
constexpr unsigned char MAP_WIDTH = 32;
constexpr unsigned char SCREEN_RESIZE = 2;





enum class Cell
{
	Wall,
	Empty,
	Chest,
	NPC,
	Boulder

};

struct Position {
	short x;
	short y;

	bool operator==(const Position& i_position) {
		return this->x == i_position.x && this->y == i_position.y;
	}
};