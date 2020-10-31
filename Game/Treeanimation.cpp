#include "Treeanimation.h"

Treeanimation::Treeanimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation2(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	counter = 0;

	treeanimation.setSize(sf::Vector2f(960.0f, 1080.0f));
	treeanimation.setOrigin(treeanimation.getSize().x / 2.0f, 0);
	treeanimation.setPosition(0.0f, 0.0f);
	treeanimation.setTexture(texture);
} 

Treeanimation::~Treeanimation()
{
}

void Treeanimation::Tree(sf::Texture* texture)
{
	tree.setSize(sf::Vector2f(960.0f, 1080.0f));
	tree.setOrigin(tree.getSize().x / 2.0f, 0);
	tree.setPosition(0.0f, 0.0f);
	tree.setTexture(texture);
}

void Treeanimation::Update(float deltaTime)
{
		row = 0;

	animation2.Update(row, deltaTime);
	treeanimation.setTextureRect(animation2.uvRect);
}

void Treeanimation::StartDraw()
{
	counter = 180;
}


void Treeanimation::Draw(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
	{
		StartDraw();
		if(counter > 0)
			window.draw(treeanimation);
	}
	else
	{
		window.draw(tree);
	}

	--counter;
}