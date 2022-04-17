#pragma once

#include "Consts.hpp"
#include "VerletObject.hpp"

#include <SFML/Graphics.hpp>

namespace stw
{
	class VerletSolver
	{
	public:
		inline static const sf::Vector2f GRAVITY = { 0.0f, G * 100 };

		explicit VerletSolver(std::shared_ptr<std::vector<VerletObject>> objects);

		void Update(float deltaTime) const;
	private:
		std::shared_ptr<std::vector<VerletObject>> objects_;

		void UpdatePositions(float deltaTime) const;
		void ApplyGravity() const;
	};
}