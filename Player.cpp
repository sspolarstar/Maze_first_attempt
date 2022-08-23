#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	facesRight = true;

	body.setSize(sf::Vector2f((float)CELL_SIZE, (float)CELL_SIZE));
	body.setOrigin(sf::Vector2f(body.getSize().x / 2.0f, body.getSize().y / 2.0f));
	//body.setPosition(600.0f, 720.0f/2.0f);
	body.setTexture(texture);


}

Player::~Player()
{
	//do nothing
}

void Player::Update(float deltaTime)
{

	//Player animations
	sf::Vector2u walkRight(0, 4);
	sf::Vector2u walkUp(17, 21);
	sf::Vector2u walkDown(10, 12);
	sf::Vector2u holdStill(6, 8);

	//player movements
	sf::Vector2f movement(0.0f, 0.0f);
	sf::Vector2u rowLocator;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		movement.x -= speed * deltaTime;
		rowLocator = walkRight; //actually left!
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		movement.y -= speed * deltaTime;
		rowLocator = walkUp;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		movement.y += speed * deltaTime;
		rowLocator = walkDown;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		movement.x += speed * deltaTime;
		rowLocator = walkRight;
	}
	if (movement.x == 0) {
		//row = 0;
		rowLocator = holdStill;
	}
	else 
	{
		//row = 1;
		if (movement.x > 0.0f)
			facesRight = true;
		else
			facesRight = false;
	}
	//end player movements


	animation.Update(row, rowLocator, deltaTime, facesRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
