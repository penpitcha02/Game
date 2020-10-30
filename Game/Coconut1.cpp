#include "Coconut1.h"

Coconut1::Coconut1(sf::Texture* texture, float speed)
{
	coconut1.setSize(sf::Vector2f(375.0f, 531.25f));
	coconut1.setPosition(2560.0f, 440.0f);
	coconut1.setTexture(texture);
}

Coconut1::~Coconut1()
{
}

void Coconut1::Movement(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	do {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			movement.y -= speed * deltaTime;
	} while (coconut1.getPosition().y < 1000.0f);

	coconut1.move(movement);
}

void Coconut1::Draw(sf::RenderWindow& window)
{
	window.draw(coconut1);
}

