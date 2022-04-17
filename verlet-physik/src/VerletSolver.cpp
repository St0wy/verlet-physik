#include "VerletSolver.hpp"

stw::VerletSolver::VerletSolver(std::shared_ptr<std::vector<VerletObject>> objects) :
	objects_(std::move(objects))
{
}

void stw::VerletSolver::Update(const float deltaTime) const
{
	ApplyGravity();
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
