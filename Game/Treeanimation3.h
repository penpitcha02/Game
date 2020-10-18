#pragma once
#include<SFML/Graphics.hpp>
#include"Animation2.h"

class Treeanimation3
{
public:
	Treeanimation3(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Treeanimation3();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return treeanimation3.getPosition(); }


private:
	sf::RectangleShape treeanimation3;
	Animation2 animation2;
	unsigned int row;
	float speed;
};


