#pragma once

#include <SFML/Graphics.hpp>

namespace stw
{
	constexpr unsigned FRAMERATE = 60;
	constexpr char WINDOW_NAME[] = "Verlet Physik";

	constexpr int WINDOW_WIDTH = 800;
	constexpr int WINDOW_HEIGHT = 800;
	static const sf::Vector2f CENTER_SCREEN = { WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f };

	constexpr float CONSTRAINT_RADIUS = WINDOW_HEIGHT / 2.0f * 0.8f;

	constexpr float G = 9.81f;

	namespace colors
	{
		static const sf::Color RAISIN_BLACK(34, 30, 34);
		static const sf::Color DARK_PURPLE(49, 38, 62);
		static const sf::Color ENGLISH_VIOLET(68, 53, 91);
		static const sf::Color MARIGOLD(236, 167, 44);
		static const sf::Color FLAME(238, 86, 34);
	}
}
