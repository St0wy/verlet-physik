#include "VerletObject.hpp"

#include "spdlog/spdlog.h"

stw::VerletObject::VerletObject(std::unique_ptr<sf::Shape> shape) :
	shape(std::move(shape))
{

}

void stw::VerletObject::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	shape->setPosition(positionCurrent);
	target.draw(*shape, states);
}

void stw::VerletObject::UpdatePosition(const float deltaTime)
{
	const sf::Vector2f velocity = positionCurrent - positionOld;

	// Save current position
	positionOld = positionCurrent;

	// Perform verlet integration
	positionCurrent += velocity + acceleration * deltaTime * deltaTime;

	spdlog::debug("\n");
	spdlog::debug(deltaTime);
	spdlog::debug("PositionCurrent : X:{0}, Y:{1}", positionCurrent.x, positionCurrent.y);
	spdlog::debug("PositionOld : X:{0}, Y:{1}", positionOld.x, positionOld.y);
	spdlog::debug("Velocity : X:{0}, Y:{1}", velocity.x, velocity.y);
	spdlog::debug("Acceleration :  X:{0}, Y:{1}", acceleration.x, acceleration.y);

	// Reset acceleration
	acceleration = {};
}

void stw::VerletObject::Accelerate(const sf::Vector2f acc)
{
	acceleration += acc;
}
