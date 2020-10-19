#include "Machine.h"

Machine::Machine(sf::Texture* texture)
{
	machine.setSize(sf::Vector2f(375.0f, 531.25f));
	machine.setPosition(2560.0f, 440.0f);
	machine.setTexture(texture);
}

Machine::~Machine()
{
}

void Machine::Draw(sf::RenderWindow& window)
{
	window.draw(machine);
}

bool Machine::isMouseOver(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float mchPosx = machine.getPosition().x;
	float mchPosy = machine.getPosition().y;

	float mchxPosWidth = machine.getPosition().x + machine.getLocalBounds().width;
	float mchyPosHeight = machine.getPosition().y + machine.getLocalBounds().height;

	if (mouseX < mchxPosWidth && mouseX > mchPosx && mouseY < mchyPosHeight && mouseY > mchPosy);
	{
		return true;
	}
	return false;
}
