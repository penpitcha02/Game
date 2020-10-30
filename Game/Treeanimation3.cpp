#include "Treeanimation3.h"

Treeanimation3::Treeanimation3(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation2(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;


	treeanimation3.setSize(sf::Vector2f(960.0f, 1080.0f));
	treeanimation3.setOrigin(treeanimation3.getSize().x / 2.0f, 0);
	treeanimation3.setPosition(850.0f, 0.0f);
	treeanimation3.setTexture(texture);
}

Treeanimation3::~Treeanimation3()
{
}

void Treeanimation3::Update(float deltaTime)
{
		row = 0;

	animation2.Update(row, deltaTime);
	treeanimation3.setTextureRect(animation2.uvRect);
}


void Treeanimation3::Draw(sf::RenderWindow& window)
{
	window.draw(treeanimation3);
}