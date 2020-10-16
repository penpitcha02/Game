#include "Sword.h"

Sword::Sword(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	sword.setSize(sf::Vector2f(300.0f, 425.0f));
	sword.setOrigin(sword.getSize().x / 2.0f, 0);
	sword.setPosition(1920.0f, 575.0f);
	sword.setTexture(texture);
}

Sword::~Sword()
{
}

void Sword::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;

	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.Update(row, deltaTime, faceRight);
	sword.setTextureRect(animation.uvRect);
	sword.move(movement);

	//Collision screen
	//Left collossion
	if (sword.getPosition().x < 0.f)
		sword.setPosition(0.f, sword.getPosition().y);
	//Right collosion
	if (sword.getPosition().x + sword.getGlobalBounds().width > 3840.0f)
		sword.setPosition(3840.0f - sword.getGlobalBounds().width, sword.getPosition().y);
}

void Sword::Draw(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		window.draw(sword);
}
