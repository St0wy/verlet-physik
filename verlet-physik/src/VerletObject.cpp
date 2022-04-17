#include "VerletObject.hpp"

stw::VerletObject::VerletObject(std::unique_ptr<sf::Shape> shape) :
	shape(std::move(shape))
{

}

void stw::VerletObject::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	shape->setPosition(positionCurrent);
	target.draw(*shape, states);
}
