#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"


class Knife
{
public:
	Knife(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Knife();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return knife.getPosition(); }


private:
	sf::RectangleShape knife;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};


