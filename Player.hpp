#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MapCollider.hpp"
#include "Animation.hpp"
#include "Global.hpp"

class Player
{
private:
	Position position;
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();
	
	void Update(float deltaTime, std::array<std::array< Cell, MAP_HEIGHT>, MAP_WIDTH>& mapRef);
	void Draw(sf::RenderWindow& window);
	//so, a position struct is a short, and a the mapRef needs... shorts, hooray! but, the actual sprite is at a
	//floating point vector, are they not?

	//OR that's what they'd want me to believe, but surely the value of the character is at a whole pixel address!
	Position getPosition() { return position; }

	void setPosition(short i_x, short i_y) { this->position.x = i_x; this->position.y = i_y; }
	void move(short i_x, short i_y);
	//Collider getCollider() { return Collider(body); }
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool facesRight;


};

