#include "Spawner.hpp"

#include <utility>
#include <spdlog/spdlog.h>

stw::Spawner::Spawner(
	std::shared_ptr<std::vector<VerletObject>> objects,
	const sf::Vector2f pos,
	const float timeToSpawn) :
	position_(pos), timeToSpawn_(timeToSpawn), spawnTimer_(), objects_(std::move(objects))
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
	constexpr float shapeRadius = 30.0f;
	objects_->push_back(VerletObject(shapeRadius, colors::ENGLISH_VIOLET, position_));
}
