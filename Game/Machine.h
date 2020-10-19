#pragma once
#include <SFML/Graphics.hpp>

class Machine
{
public:
	Machine(sf::Texture* texture);
	~Machine();

	void Draw(sf::RenderWindow& window);

	bool isMouseOver(sf::RenderWindow& window);

private:
	sf::RectangleShape machine;
};