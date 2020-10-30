#include "Treeanimation.h"

Treeanimation::Treeanimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, int Timee) :
	animation2(texture, imageCount, switchTime)
{
	this->speed = speed;
	Timer = Timee;
	row = 0;


	treeanimation.setSize(sf::Vector2f(960.0f, 1080.0f));
	treeanimation.setOrigin(treeanimation.getSize().x / 2.0f, 0);
	treeanimation.setPosition(0.0f, 0.0f);
	treeanimation.setTexture(texture);
} 

Treeanimation::~Treeanimation()
{
}

void Treeanimation::Update(float deltaTime)
{
		row = 0;

	animation2.Update(row, deltaTime);
	treeanimation.setTextureRect(animation2.uvRect);
}


void Treeanimation::Draw(sf::RenderWindow& window)
{
	window.draw(treeanimation);
}