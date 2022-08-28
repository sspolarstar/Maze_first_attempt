#include "MapCollider.hpp"

bool map_collision(short i_x, short i_y, const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& mapRef)
{
	bool output = false;

	//Getting the exact position.
	float cell_x = i_x / static_cast<float>(CELL_SIZE);
	float cell_y = i_y / static_cast<float>(CELL_SIZE);

	//first I'll check the four (possible) intercepted cells. 
	for (unsigned char a = 0; a < 4; a++) {

		short x = 0;
		short y = 0;

		switch (a)
		{
		case 0: //Top left cell
		{
			x = static_cast<short>(floor(cell_x));
			y = static_cast<short>(floor(cell_y));

			break;
		}
		case 1: //Top right cell
		{
			x = static_cast<short>(ceil(cell_x));
			y = static_cast<short>(floor(cell_y));

			break;
		}
		case 2: //Bottom left cell
		{
			x = static_cast<short>(floor(cell_x));
			y = static_cast<short>(ceil(cell_y));

			break;
		}
		case 3: //Bottom right cell
		{
			x = static_cast<short>(ceil(cell_x));
			y = static_cast<short>(ceil(cell_y));
		}
		}

		// Now, let us check all the values so that we can give the collider a function!

		//first, we need this not to break on the edge of the screen, eh?
		if (0 <= x && 0 <= y && MAP_HEIGHT > y && MAP_WIDTH > x) {
			//now, is it a wall?
			if (Cell::Wall == mapRef[x][y]) {
				output = 1;
			}
			if (Cell::Next_Area == mapRef[x][y]) {

			}
		}

	}



	return output;
}
