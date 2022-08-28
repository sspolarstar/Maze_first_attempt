#include "mazeBuilder.hpp"



void DrawMap(sf::RenderWindow& window, const std::array<std::array< Cell, MAP_HEIGHT>, MAP_WIDTH> MapSketch)
{
	sf::Sprite sprite;
	sf::Texture texture;
	texture.loadFromFile("img/graySquare.png");
	sprite.setTexture(texture);
	for (unsigned char a = 0; a < MAP_WIDTH; a++)
	{
		for (unsigned char b = 0; b < MAP_HEIGHT; b++)
		{
			sprite.setPosition(static_cast<float>(CELL_SIZE * a), static_cast<float>(CELL_SIZE * b));
			switch (MapSketch[a][b])
			{
			case Cell::Wall:
				sprite.setTextureRect(sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));
				window.draw(sprite);
				break;
			case Cell::Boulder:
				window.draw(sprite);
				break;
			}

		}
	}
	//window.draw(body);
} //end DrawMap function

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> convertSketch(const std::array<std::string, MAP_HEIGHT>& i_map_sketch, Player& player)
{
	std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> output_map{};
	for (unsigned char a = 0; a < (MAP_HEIGHT ); a++) {
		for (unsigned char b = 0; b < (MAP_WIDTH ); b++) {
			output_map[b][a] = Cell::Empty;
			switch (i_map_sketch[a][b])
			{
				case '*': 
					//this is the walls
					output_map[b][a] = Cell::Wall;
					break;
			
				case 'p': 
					player.setPosition(b*CELL_SIZE, a*CELL_SIZE);
					break;
			
				case 'c': 
					//this will be a chest!
					output_map[b][a] = Cell::Chest;
					break;
			
				case 'b': 
					//boulder time
					output_map[b][a] = Cell::Boulder;
					break;
				case 'n':
					//NPC
					output_map[b][a] = Cell::NPC;
					break;
	

			} //end switch

		} //end for loop b

	}//end for loop a

	return output_map;
}


