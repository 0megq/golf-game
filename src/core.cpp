#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "core.h"

// Create an abstraction for entry, update, input, draw, and exit
// Then we build our game using these

int main()
{
	// INIT
	sf::Vector2u size{960, 540};
	unsigned fpsLimit = 144;
	auto window = sf::RenderWindow(sf::VideoMode(size), "CMake SFML Project");
	window.setFramerateLimit(fpsLimit);

	initGame();

	sf::Clock clock;
	while (window.isOpen())
	{
		// INPUT
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				// NOTE: Window is closed immediately!
				window.close();
			}
		}

		// GAME LOGIC
		float delta = clock.restart().asSeconds();
		gameUpdate(delta, size.x, size.y);

		// DRAWING
		window.clear();
		gameDraw(window);
		window.display();
	}

	// END
	closeGame();

	return 0;
}
