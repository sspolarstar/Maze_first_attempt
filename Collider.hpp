#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	bool CheckCollision(Collider other, float push);
	
	void move(float dx, float dy) { body.move(dx, dy); }
	
	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body; 
};

