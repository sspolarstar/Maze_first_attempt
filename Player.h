#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Animation.h"
#include "Global.hpp"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();
	
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	
	sf::Vector2f getPosition() { return body.getPosition(); }
	void setPosition(sf::Vector2f position) { body.setPosition(position); }

	Collider getCollider() { return Collider(body); }
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool facesRight;


};

