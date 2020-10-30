#pragma once
#include <SFML/Graphics.hpp>

class Coconut1
{
public:
	Coconut1(sf::Texture* texture, float speed);
	~Coconut1();

	void Movement(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape coconut1;
	float speed;
};