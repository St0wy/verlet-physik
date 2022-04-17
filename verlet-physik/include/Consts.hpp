#pragma once

namespace stw
{
	constexpr unsigned FRAMERATE = 60;
	constexpr char WINDOW_NAME[] = "Verlet Physik";

	constexpr int WINDOW_SCALE = 100;
	constexpr int WINDOW_WIDTH = 16 * WINDOW_SCALE;
	constexpr int WINDOW_HEIGHT = 9 * WINDOW_SCALE;

	constexpr float GRAVITY = 9.81f;

	namespace colors
	{
		static const sf::Color RAISIN_BLACK(34, 30, 34);
		static const sf::Color DARK_PURPLE(49, 38, 62);
		static const sf::Color ENGLISH_VIOLET(68, 53, 91);
		static const sf::Color MARIGOLD(236, 167, 44);
		static const sf::Color FLAME(238, 86, 34);
	}
}
