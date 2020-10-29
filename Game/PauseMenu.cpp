#include "PauseMenu.h"

PauseMenu::PauseMenu(float width, float height)
{
	if (!font.loadFromFile("fonts/arialbi.ttf"))
		printf("LOAD MAI DAI I SUS");

	//Play
	pauseMenu.setFont(font);
	pauseMenu.setFillColor(sf::Color::Blue);
	pauseMenu.setString("QUIT");
	pauseMenu.setCharacterSize(80);
	pauseMenu.setPosition(960, 540);
}

PauseMenu::~PauseMenu()
{
}

//Draw PauseMenu
void PauseMenu::Draw(sf::RenderWindow& window)
{
	window.draw(pauseMenu);
}