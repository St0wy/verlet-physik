#include "DemoWindow.hpp"

#include "Consts.hpp"

#include <iostream>

stw::DemoWindow::DemoWindow() :
	window_(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Close),
	objects_(std::make_shared<std::vector<VerletObject>>())
{
	window_.setVerticalSyncEnabled(true);
	window_.setFramerateLimit(FRAMERATE);
}

void stw::DemoWindow::StartMainLoop()
{
	const sf::Vector2f centerScreen = { WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f };

	// Create static object
	auto shape = std::make_unique<sf::CircleShape>(50.f);
	shape->setFillColor(colors::ENGLISH_VIOLET);
	objects_->push_back(VerletObject(std::move(shape)));
	objects_->at(0).positionCurrent = centerScreen;

	while (window_.isOpen())
	{

		// Handle events
		sf::Event event{};
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();
		}

		if (window_.hasFocus())
		{
			// Step the physics
		}

		// Clear the window
		window_.clear(colors::RAISIN_BLACK);

		// Render all the entities
		for (const auto& obj : *objects_)
		{
			window_.draw(obj);
		}

		// End the current frame
		window_.display();
	}
}
