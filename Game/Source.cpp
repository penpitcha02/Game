#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int page_number;

int main()
{
		//MainMenu
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game!", sf::Style::Fullscreen);

		//MainMenu Text
		MainMenu mainmenu(1920,1080);

		//MenuBackground
		sf::RectangleShape menubackground(sf::Vector2f(1920.0f, 1080.0f));
		menubackground.setPosition(0.0f, 00.0f);
		sf::Texture menubackgroundTexture;
		menubackgroundTexture.loadFromFile("img/Menubackground.png");
		menubackground.setTexture(&menubackgroundTexture);

	//MainMenu Window
	while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::KeyReleased:
					switch (evnt.key.code)
					{
					case sf::Keyboard::Return:
						if (mainmenu.mainMenuPressed() == 0)
						{
							window.close();
							page_number = 1;
						}
						if (mainmenu.mainMenuPressed() == 1)
						{
							window.close();
							page_number = 2;
						}
						if (mainmenu.mainMenuPressed() == 2)
						{
							window.close();
							page_number = 3;
						}
						break;

					case sf::Keyboard::Up:
						mainmenu.moveUp();
						break;
					case sf::Keyboard::Down:
						mainmenu.moveDown();
						break;
					}
					break;
				}
			}

			//////Render
			window.clear();
			window.draw(menubackground);
			mainmenu.Draw(window);
			window.display();
			window.setFramerateLimit(60);
		}

		//Animation Time
		float deltaTime = 0.0f;
		sf::Clock clock;


		//View
		sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920.0f, 1080.0f));

		//Grandpa
		sf::Texture playerTexture;
		playerTexture.loadFromFile("img/grandpa2.png");

		Player player(&playerTexture, sf::Vector2u(4, 2), 0.3f, 500.0f);


		//Knife
		sf::Texture knifeTexture;
		knifeTexture.loadFromFile("img/knife2.png");

		Knife knife(&knifeTexture, sf::Vector2u(4, 2), 0.3f, 500.0f);


		//Sword
		sf::Texture swordTexture;
		swordTexture.loadFromFile("img/sword.png");

		Sword sword(&swordTexture, sf::Vector2u(4, 2), 0.3f, 500.0f);


		//Machine
		sf::Texture machineanimationTexture;
		machineanimationTexture.loadFromFile("img/machineanimation.png");

		Machineanimation machineanimation(&machineanimationTexture, sf::Vector2u(4, 2), 0.3f, 500.0f);

		sf::Texture machineTexture;
		machineTexture.loadFromFile("img/machine.png");

		Machine machine(&machineTexture);


		//Tree
		sf::Texture treeanimationTexture;
		treeanimationTexture.loadFromFile("img/treeanimation.png");

		Treeanimation treeanimation(&treeanimationTexture, sf::Vector2u(4, 1), 0.25f, 500.0f,0);

		sf::RectangleShape tree(sf::Vector2f(960.0f, 1080.0f));
		tree.setOrigin(tree.getSize().x / 2.0f, 0);
		tree.setPosition(0.0f, 0.0f);
		sf::Texture treeTexture;
		treeTexture.loadFromFile("img/tree.png");
		tree.setTexture(&treeTexture);

		//Tree2
		sf::Texture treeanimation2Texture;
		treeanimation2Texture.loadFromFile("img/treeanimation2.png");

		Treeanimation2 treeanimation2(&treeanimation2Texture, sf::Vector2u(4, 1), 0.25f, 500.0f);

		sf::RectangleShape tree2(sf::Vector2f(960.0f, 1080.0f));
		tree2.setOrigin(tree2.getSize().x / 2.0f, 0);
		tree2.setPosition(1700.0f, 0.0f);
		sf::Texture tree2Texture;
		tree2Texture.loadFromFile("img/tree2.png");
		tree2.setTexture(&tree2Texture);

		//Tree3
		sf::Texture treeanimation3Texture;
		treeanimation3Texture.loadFromFile("img/treeanimation3.png");

		Treeanimation3 treeanimation3(&treeanimation3Texture, sf::Vector2u(4, 1), 0.25f, 500.0f);

		sf::RectangleShape tree3(sf::Vector2f(960.0f, 1080.0f));
		tree3.setOrigin(tree3.getSize().x / 2.0f, 0);
		tree3.setPosition(820.0f, 0.0f);
		sf::Texture tree3Texture;
		tree3Texture.loadFromFile("img/tree3.png");
		tree3.setTexture(&tree3Texture);


		//Coconut1
		sf::Texture coconut1Texture;
		coconut1Texture.loadFromFile("img/coconut1.png");

		Coconut1 coconut1(&coconut1Texture,500.0f);


		//Shop
		sf::RectangleShape shop(sf::Vector2f(5760.0f, 1080.0f));
		shop.setPosition(-960.0f, 0.0f);
		sf::Texture shopTexture;
		shopTexture.loadFromFile("img/shop.png");
		shop.setTexture(&shopTexture);


		//Background
		sf::RectangleShape background(sf::Vector2f(5760.0f, 1080.0f));
		background.setPosition(-960.0f, 0.0f);
		sf::Texture backgroundTexture;
		backgroundTexture.loadFromFile("img/background4.png");
		background.setTexture(&backgroundTexture);

	//Game Window
	if (page_number == 1)
	{
		//Play
		sf::RenderWindow window_play(sf::VideoMode(1920, 1080), "Play!", sf::Style::Fullscreen);
		while (window_play.isOpen())
		{
			deltaTime = clock.restart().asSeconds();

			sf::Event evnt;
			while (window_play.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::KeyReleased:
					switch (evnt.key.code)
					{
					case sf::Keyboard::Escape:
						window_play.close();
						main();
						break;
					}
					break;
				}

			}

			player.Update(deltaTime);
			knife.Update(deltaTime);
			sword.Update(deltaTime);

			machineanimation.Update(deltaTime);

			treeanimation.Update(deltaTime);
			treeanimation2.Update(deltaTime);
			treeanimation3.Update(deltaTime);

		

			view.setCenter(player.GetPosition());

			//////Render

			window_play.clear();

			//View
			window_play.setView(view);

			//Background
			window_play.draw(background);

			//Tree
			if (evnt.key.code == sf::Keyboard::Z)
				treeanimation.Draw(window_play);
			else
				window_play.draw(tree);

			//Tree2
			if (evnt.key.code == sf::Keyboard::C)
				treeanimation2.Draw(window_play);
			else
				window_play.draw(tree2);

			//Tree3
			if (evnt.key.code == sf::Keyboard::X)
				treeanimation3.Draw(window_play);
			else
				window_play.draw(tree3);

			//Coconut1
			if (evnt.key.code == sf::Keyboard::Space)
			{
				coconut1.Draw(window_play);
			}

			//Player&Weapon
			sword.Draw(window_play);
			player.Draw(window_play);
			knife.Draw(window_play);

			//Shop
			window_play.draw(shop);

			//Machine
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (machine.isMouseOver(window_play))
					machineanimation.Draw(window_play);
			}
			else
				machine.Draw(window_play);
				
			window_play.display();
			window_play.setFramerateLimit(60);
		}
	}
	return 0;
}



