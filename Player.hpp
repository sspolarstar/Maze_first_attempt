#pragma once
#include <SFML/Graphics.hpp>
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
	
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	
	sf::Vector2f getPosition() { return body.getPosition(); }
	void setPosition(sf::Vector2f position) { body.setPosition(position); }

	//Collider getCollider() { return Collider(body); }
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool facesRight;


};

