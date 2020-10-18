#pragma once
#include<SFML/Graphics.hpp>
#include"Animation2.h"

class Treeanimation2
{
public:
	Treeanimation2(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Treeanimation2();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return treeanimation2.getPosition(); }


private:
	sf::RectangleShape treeanimation2;
	Animation2 animation2;
	unsigned int row;
	float speed;
};


