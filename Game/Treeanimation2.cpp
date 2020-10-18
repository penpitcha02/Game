#include "Treeanimation2.h"

Treeanimation2::Treeanimation2(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation2(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;


	treeanimation2.setSize(sf::Vector2f(960.0f, 1080.0f));
	treeanimation2.setOrigin(treeanimation2.getSize().x / 2.0f, 0);
	treeanimation2.setPosition(1700.0f, 40.0f);
	treeanimation2.setTexture(texture);
}

Treeanimation2::~Treeanimation2()
{
}

void Treeanimation2::Update(float deltaTime)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		row = 0;

	animation2.Update(row, deltaTime);
	treeanimation2.setTextureRect(animation2.uvRect);

}


void Treeanimation2::Draw(sf::RenderWindow& window)
{
	window.draw(treeanimation2);
}