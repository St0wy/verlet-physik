#pragma once

#include <SFML/Graphics.hpp>

#include "Consts.hpp"

namespace stw
{
	class VerletObject final : public sf::Drawable
	{
	public:
		static constexpr float DEFAULT_RADIUS = 30.0f;

		sf::Vector2f positionCurrent;
		sf::Vector2f positionOld;
		sf::Vector2f acceleration;
		std::shared_ptr<sf::CircleShape> shape;

		explicit VerletObject(std::unique_ptr<sf::CircleShape> shape);
		explicit VerletObject(float radius = DEFAULT_RADIUS, sf::Color color = colors::FLAME, sf::Vector2f pos = {});

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void UpdatePosition(float deltaTime);

		void Accelerate(sf::Vector2f acc);

		[[nodiscard]] float GetRadius() const;
	};
}