#pragma once

#include <SFML/Graphics.hpp>

namespace stw
{
	class VerletObject final : public sf::Drawable
	{
	public:
		sf::Vector2f positionCurrent;
		sf::Vector2f positionOld;
		sf::Vector2f acceleration;
		std::shared_ptr<sf::Shape> shape;

		explicit VerletObject(std::unique_ptr<sf::Shape> shape);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}