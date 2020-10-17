#include "Knife.h"

Knife::Knife(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	knife.setSize(sf::Vector2f(375.0f, 531.25f));
	knife.setOrigin(knife.getSize().x / 2.0f, knife.getSize().x / 4.0f);
	knife.setPosition(1920.0f, 575.0f);
	knife.setTexture(texture);
}

Knife::~Knife()
{
}

void Knife::Update(float deltaTime)
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
	knife.setTextureRect(animation.uvRect);
	knife.move(movement);

	//Collision screen
	//Left collossion
	if (knife.getPosition().x < 0.f)
		knife.setPosition(0.f, knife.getPosition().y);
	//Right collosion
	if (knife.getPosition().x + knife.getGlobalBounds().width > 3840.0f)
		knife.setPosition(3840.0f - knife.getGlobalBounds().width, knife.getPosition().y);

}


void Knife::Draw(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		window.draw(knife);
}

     
