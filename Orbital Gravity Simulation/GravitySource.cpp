#include "GravitySource.h"

GravitySource::GravitySource(float pos_x, float pos_y, float strength)
{
	pos.x = pos_x;
	pos.y = pos_y;
	this->strength = strength;

	s.setPosition(pos);
	s.setFillColor(sf::Color::White);
	s.setRadius(10);
}

void GravitySource::render(sf::RenderWindow& window)
{
	window.draw(s);
}
