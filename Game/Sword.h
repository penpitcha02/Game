#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"


class Sword
{
public:
	Sword(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Sword();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return sword.getPosition(); }


private:
	sf::RectangleShape sword;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};


