#include "Ball.hpp"
#include <iostream>
#include "Logger.hpp"

namespace vg 
{
	Ball::Ball(PosCircle posCir, SpeedCircle speedCir, float radius) {
		m_texture.loadFromFile("texture_for_ball.png");
		m_posCir = posCir;
		m_speedCir = speedCir;
		m_radius = radius;
		m_circle = std::make_unique<sf::CircleShape>(m_radius);
		m_circle->setOrigin(m_radius, m_radius);
		m_circle->setTexture(&m_texture);
	}

	void Ball::move() {
		m_posCir.x += m_speedCir.x;
		m_posCir.y += m_speedCir.y;
		m_circle->setPosition(m_posCir.x, m_posCir.y);
	}

	unsigned int& Ball::GetCounter() {
		return m_counter;
	}

	bool& Ball::GetCanPlay() {
		return CanPlay;
	}

	void Ball::collision(float x) {
		if ((m_posCir.x + m_radius) >= 600)
			m_speedCir.x = -m_speedCir.x;

		if (m_posCir.x - m_radius <= 0)
			m_speedCir.x = -m_speedCir.x;

		if ((m_posCir.y - m_radius) < 0)
			m_speedCir.y = -m_speedCir.y;

		if ((m_posCir.y + m_radius >= 750) && (m_posCir.x >= x) && (m_posCir.x <= x + 120)){
			m_counter++;
			m_speedCir.y = -m_speedCir.y;
		}	

		if (m_posCir.y + m_radius >= 800) {
			m_speedCir.x = 0;
			m_speedCir.y = 0;
			CanPlay = 0;	
		}
	}

	sf::CircleShape* Ball::Get() {
		return m_circle.get();
	}
	Ball::~Ball() {
		
	}

}