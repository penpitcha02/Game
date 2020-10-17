#pragma once
#include<SFML/Graphics.hpp>
#include"Animation2.h"

class Machine
{
public:
	Machine(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Machine();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return machine.getPosition(); }


private:
	sf::RectangleShape machine;
	Animation2 animation2;
	unsigned int row;
	float speed;
};


