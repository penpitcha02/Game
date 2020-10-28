#include "MainMenu.h"

void MainMenu::initKeybinds()
{
}

MainMenu::MainMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) 
{
	this->initKeybinds();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenu::~MainMenu()
{
}

void MainMenu::endState()
{
}

void MainMenu::updateInput(const float& dt)
{
}

void MainMenu::update(const float& dt)
{
}

void MainMenu::render(sf::RenderTarget* target)
{
	
}
