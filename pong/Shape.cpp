#include "Shape.hpp"

namespace vg
{
	Rect::Rect(PosRect posR, float Speed, float width, float high) {
		m_texture.loadFromFile("texture_for_platform.png");
		m_posRect = posR;
		m_speedRect = Speed;
		m_width = width;
		m_high = high;
		rect = std::make_unique<sf::RectangleShape>(sf::Vector2f(width, high));
		rect->setPosition(m_posRect.x, m_posRect.y);
		rect->setTexture(&m_texture);
	}

	Rect::~Rect() {
	
	}

	void Rect::ChangeSpeed(float new_speed) {
		m_speedRect = new_speed;
	}

	void Rect::moveRect() {
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (m_posRect.x > 0)) {
			m_posRect.x -= m_speedRect;
			rect->setPosition(m_posRect.x, m_posRect.y);
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (m_posRect.x < 480)) {
			m_posRect.x += m_speedRect;
			rect->setPosition(m_posRect.x, m_posRect.y);
		}
	}

	float& Rect::getPosX() {
		return m_posRect.x;
	}

	sf::RectangleShape* Rect::Get() {
		return rect.get();
	}

}