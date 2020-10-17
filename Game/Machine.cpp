#include "Machine.h"

Machine::Machine(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation2(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;


	machine.setSize(sf::Vector2f(375.0f, 531.25f));
	machine.setOrigin(machine.getSize().x / 2.0f, 0);
	machine.setPosition(2800.0f, 500.0f);
	machine.setTexture(texture);
}

Machine::~Machine()
{
}

void Machine::Update(float deltaTime)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		row = 1;
	else
		row = 0;

	animation2.Update(row, deltaTime);
	machine.setTextureRect(animation2.uvRect);

}


void Machine::Draw(sf::RenderWindow& window)
{
	window.draw(machine);
}

