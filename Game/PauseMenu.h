#pragma once
#include <SFML/Graphics.hpp>

class PauseMenu
{
public:
	PauseMenu(float width, float height);

	void Draw(sf::RenderWindow& window);

	int pauseMenuPressed();

	~PauseMenu();

private:
	sf::Font font;
	sf::Text pauseMenu;
};