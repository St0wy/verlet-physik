#pragma once

#include "VerletObject.hpp"

#include <SFML/Graphics.hpp>

namespace stw
{
	class Spawner
	{
	public:
		Spawner(std::shared_ptr<std::vector<VerletObject>> objects, sf::Vector2f pos, float timeToSpawn = 0);

		void Update(float deltaTime);
		void Spawn() const;

	private:
		
		sf::Vector2f position_;
		float timeToSpawn_;
		float spawnTimer_;
		std::shared_ptr<std::vector<VerletObject>> objects_;
	};
}