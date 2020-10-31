#pragma once
#include<SFML/Graphics.hpp>
#include"Animation2.h"

class Treeanimation
{
public:
	Treeanimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Treeanimation();

	void Update(float deltaTime);
	void StartDraw();
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return treeanimation.getPosition(); }


private:
	sf::RectangleShape treeanimation;
	Animation2 animation2;
	unsigned int row;
	float speed;
	int counter;
};


