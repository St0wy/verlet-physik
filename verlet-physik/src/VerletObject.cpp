#include "VerletObject.hpp"

#include "spdlog/spdlog.h"

stw::VerletObject::VerletObject(std::unique_ptr<sf::CircleShape> shape) :
	shape(std::move(shape))
{

}

stw::VerletObject::VerletObject(const sf::Vector2f pos, const float radius, const sf::Color color) :
	VerletObject(pos, pos, radius, color)
{

}

stw::VerletObject::VerletObject(const sf::Vector2f pos, const sf::Vector2f oldPos, float radius, const sf::Color color) :
	positionCurrent(pos), positionOld(oldPos)
{
	shape = std::make_shared<sf::CircleShape>(radius);
	shape->setFillColor(color);
	shape->setOrigin(radius, radius);
}

void stw::VerletObject::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	shape->setPosition(positionCurrent);
	target.draw(*shape, states);
}

void stw::VerletObject::UpdatePosition(const float deltaTime)
{
	const sf::Vector2f velocity = positionCurrent - positionOld;

	//spdlog::debug("\n");
	//spdlog::debug("Velocity : X:{0}, Y:{1}", velocity.x, velocity.y);
	//spdlog::debug("positionCurrent : X:{0}, Y:{1}", positionCurrent.x, positionCurrent.y);
	//spdlog::debug("positionOld : X:{0}, Y:{1}", positionOld.x, positionOld.y);

	// Save current position
	positionOld = positionCurrent;

	// Perform verlet integration
	positionCurrent += velocity + acceleration * deltaTime * deltaTime;

	// Reset acceleration
	acceleration = {};
}

void stw::VerletObject::Accelerate(const sf::Vector2f acc)
{
	acceleration += acc;
}

float stw::VerletObject::GetRadius() const
{
	return shape->getRadius();
}
