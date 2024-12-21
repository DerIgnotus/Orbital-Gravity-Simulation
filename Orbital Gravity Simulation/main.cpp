#include <iostream>
#include <SFML/Graphics.hpp>
#include "GravitySource.h"
#include "Particle.h"
#include <vector>


sf::Color mapValToColor(float value)
{
	if (value < 0) value = 0;
	if (value > 1) value = 1;

	int r = 0, g = 0, b = 0;

	if (value < 0.5)
	{
		b = 255 * (1.0f - 2 * value);
		g = 255 * 2 * value;
	}
	else
	{
		g = 255 * (2.0f - 2 * value);
		r = 255 * (2 * value - 1);
	}

	return sf::Color(r, g, b);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "My Program");
	window.setFramerateLimit(60);

	std::vector<GravitySource> sources;

	sources.push_back(GravitySource(300, 400, 5000));
	sources.push_back(GravitySource(900, 400, 5000));
	//sources.push_back(GravitySource(600, 650, 4000));
	//sources.push_back(GravitySource(600, 150, 4000));

	int numParticles = 5000;

	std::vector<Particle> particles;

	for (int i = 0; i < numParticles; i++)
	{
		particles.push_back(Particle(400, 700, 2, 0.2 + (0.1 / numParticles) * i));

		float val = (float)i / (float)numParticles;

		sf::Color col = mapValToColor(val);

		particles[i].setColor(col);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		}


		window.clear();

		for (int i = 0; i < sources.size(); i++)
		{
			for (int j = 0; j < particles.size(); j++)
			{
				particles[j].updatePhysics(sources[i]);
			}
		}

		for (int i = 0; i < sources.size(); i++)
		{
			sources[i].render(window);
		}

		for (int i = 0; i < particles.size(); i++)
		{
			particles[i].render(window);
		}
		window.display();
	}

	return 0;
}