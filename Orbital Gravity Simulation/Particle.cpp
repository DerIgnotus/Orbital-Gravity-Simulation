#include "Particle.h"

Particle::Particle(float pos_x, float pos_y, float vel_x, float vel_y)
{
	pos.x = pos_x;
	pos.y = pos_y;

	vel.x = vel_x;
	vel.y = vel_y;

	s.setPosition(pos);
	s.setFillColor(sf::Color::White);
	s.setRadius(5);
}

void Particle::render(sf::RenderWindow& window)
{
	s.setPosition(pos);
	window.draw(s);
}

void Particle::updatePhysics(GravitySource& s)
{
	float distance_x = s.getPos().x - pos.x;
	float distance_y = s.getPos().y - pos.y;

	float distance = sqrt(distance_x * distance_x + distance_y * distance_y);

	float inverse_distance = 1.f / distance;

	float normalized_x = inverse_distance * distance_x;
	float normalized_y = inverse_distance * distance_y;

	float inverse_square_dropoff = inverse_distance * inverse_distance;

	float acceleration_x = normalized_x * s.getStrength() * inverse_square_dropoff;
	float acceleration_y = normalized_y * s.getStrength() * inverse_square_dropoff;

	vel.x += acceleration_x;
	vel.y += acceleration_y;

	pos.x += vel.x;
	pos.y += vel.y;
}

void Particle::setColor(sf::Color col)
{
	s.setFillColor(col);
}
