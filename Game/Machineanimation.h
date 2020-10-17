#pragma once
#include<SFML/Graphics.hpp>
#include"Animation2.h"

class Machineanimation
{
public:
	Machineanimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Machineanimation();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return machineanimation.getPosition(); }


private:
	sf::RectangleShape machineanimation;
	Animation2 animation2;
	unsigned int row;
	float speed;
};


