#include "DemoWindow.hpp"

#include "Consts.hpp"
#include "VerletSolver.hpp"
#include "Spawner.hpp"

stw::DemoWindow::DemoWindow() :
	window_(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Close),
	objects_(std::make_shared<std::vector<VerletObject>>())
{
	window_.setVerticalSyncEnabled(true);
	window_.setFramerateLimit(FRAMERATE);
}

void stw::DemoWindow::StartMainLoop()
{
	// Create static object
	sf::CircleShape backgroundCircle(CONSTRAINT_RADIUS, 100);
	backgroundCircle.setOrigin(CONSTRAINT_RADIUS, CONSTRAINT_RADIUS);
	backgroundCircle.setPosition(CENTER_SCREEN.x, CENTER_SCREEN.y);
	backgroundCircle.setFillColor(colors::RAISIN_BLACK);

	Spawner spawner(objects_, sf::Vector2f(CENTER_SCREEN.x + 10, CENTER_SCREEN.y - 200), 0.5f);

	const VerletSolver solver(objects_);

	sf::Clock clock;
	while (window_.isOpen())
	{
		sf::Time deltaTime = clock.restart();

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
			solver.Update(deltaTime.asSeconds());
			spawner.Update(deltaTime.asSeconds());
		}

		// Clear the window
		window_.clear(colors::DARK_PURPLE);

		// Render
		window_.draw(backgroundCircle);
		for (const auto& obj : *objects_)
		{
			window_.draw(obj);
		}

		// End the current frame
		window_.display();
	}
}
