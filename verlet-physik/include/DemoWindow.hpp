#pragma once

#include <SFML/Graphics.hpp>

#include "VerletObject.hpp"

namespace stw
{
	class DemoWindow
	{
	public:
		DemoWindow();
		void StartMainLoop();

	private:
		sf::RenderWindow window_;
		std::shared_ptr<std::vector<VerletObject>> objects_;
	};
}
