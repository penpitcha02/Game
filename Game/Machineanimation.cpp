#include "Machineanimation.h"

Machineanimation::Machineanimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation2(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;


	machineanimation.setSize(sf::Vector2f(375.0f, 531.25f));
	machineanimation.setOrigin(machineanimation.getSize().x / 2.0f, 0);
	machineanimation.setPosition(2800.0f, 460.0f);
	machineanimation.setTexture(texture);

}

Machineanimation::~Machineanimation()
{
}

void Machineanimation::Update(float deltaTime)
{
		row = 1;

	animation2.Update(row, deltaTime);
	machineanimation.setTextureRect(animation2.uvRect);

}


void Machineanimation::Draw(sf::RenderWindow& window)
{
		window.draw(machineanimation);
}

