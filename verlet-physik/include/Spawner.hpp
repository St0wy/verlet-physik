#pragma once

#include "VerletObject.hpp"

#include <SFML/Graphics.hpp>

namespace stw
{
	class Spawner
	{
	public:
		Spawner(
			std::shared_ptr<std::vector<VerletObject>> objects,
			sf::Vector2f pos,
			float timeToSpawn = 0,
			sf::Vector2f shootVector = {});

		void Update(float deltaTime);
		void Spawn() const;
		void Start();

	private:
		std::shared_ptr<std::vector<VerletObject>> objects_;
		sf::Vector2f position_;
		float timeToSpawn_;
		float spawnTimer_;
		sf::Vector2f shootVector_;
		bool isStarted_;
	};
}