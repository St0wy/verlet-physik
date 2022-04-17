#include "Spawner.hpp"

#include <utility>
#include <spdlog/spdlog.h>

stw::Spawner::Spawner(
	std::shared_ptr<std::vector<VerletObject>> objects,
	const sf::Vector2f pos,
	const float timeToSpawn,
	const sf::Vector2f shootVector) :
	objects_(std::move(objects)),
	position_(pos),
	timeToSpawn_(timeToSpawn),
	spawnTimer_(),
	shootVector_(shootVector)
{
}

void stw::Spawner::Update(const float deltaTime)
{
	spawnTimer_ += deltaTime;

	if (spawnTimer_ >= timeToSpawn_)
	{
		spawnTimer_ -= timeToSpawn_;
		Spawn();
	}
}

void stw::Spawner::Spawn() const
{
	constexpr float shapeRadius = 10.0f;
	objects_->push_back(VerletObject(position_ + shootVector_, position_, shapeRadius, colors::ENGLISH_VIOLET));
}
