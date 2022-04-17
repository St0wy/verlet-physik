#include "VerletSolver.hpp"
#include "VecUtils.hpp"

stw::VerletSolver::VerletSolver(std::shared_ptr<std::vector<VerletObject>> objects) :
	objects_(std::move(objects))
{
}

void stw::VerletSolver::Update(const float deltaTime) const
{
	ApplyGravity();
	ApplyConstraints();
	SolveCollisions();
	UpdatePositions(deltaTime);
}

void stw::VerletSolver::UpdatePositions(const float deltaTime) const
{
	for (auto& object : *objects_)
	{
		object.UpdatePosition(deltaTime);
	}
}

void stw::VerletSolver::ApplyGravity() const
{
	for (auto& object : *objects_)
	{
		object.Accelerate(GRAVITY);
	}
}

void stw::VerletSolver::ApplyConstraints() const
{
	const sf::Vector2f constraintPosition = CENTER_SCREEN;

	for (auto& object : *objects_)
	{
		const sf::Vector2f toObj = object.positionCurrent - constraintPosition;
		const float objectRadius = object.GetRadius();
		// ReSharper disable once CppTooWideScopeInitStatement
		const float dist = magnitude(toObj);

		if (dist > CONSTRAINT_RADIUS - objectRadius)
		{
			const sf::Vector2f normalized = toObj / dist;
			object.positionCurrent = constraintPosition + normalized * (CONSTRAINT_RADIUS - objectRadius);
		}
	}
}

void stw::VerletSolver::SolveCollisions() const
{
	const auto count = objects_->size();
	for (std::size_t i = 0; i < count; ++i)
	{
		VerletObject& object1 = objects_->at(i);
		for (std::size_t j = i + 1; j < count; ++j)
		{
			VerletObject& object2 = objects_->at(j);
			const sf::Vector2f collisionAxis = object1.positionCurrent - object2.positionCurrent;
			const float dist = magnitude(collisionAxis);
			const float addedRadius = object1.GetRadius() + object2.GetRadius();
			if (dist < addedRadius)
			{
				const sf::Vector2f normalized = collisionAxis / dist;
				const float delta = addedRadius - dist;

				const sf::Vector2f move = 0.5f * delta * normalized;
				object1.positionCurrent += move;
				object2.positionCurrent -= move;
			}
		}
	}
}
