#include "Button.hpp"


namespace vg
{
	Button::Button(PosButton pos_button, std::string str) {
		m_font.loadFromFile("alg.ttf");
		m_str = str;
		m_text_for_button.setFont(m_font);
		m_text_for_button.setString(str);
		m_text_for_button.setCharacterSize(40);
		m_text_for_button.setOrigin(55, 25);
		m_text_for_button.setPosition(pos_button.x + 150 / 2.0, pos_button.y + 50 / 2.0);

		m_pos_button = pos_button;
		m_button = std::make_unique<sf::RectangleShape>(sf::Vector2f(150, 50));
		m_button->setFillColor(sf::Color(170, 0, 0));
		m_button->setPosition(m_pos_button.x, m_pos_button.y);
	}

	sf::RectangleShape* Button::Get() {
		return m_button.get();
	}

	void Button::SetColorTextButton(int R, int G, int B) {
		m_text_for_button.setFillColor(sf::Color(R, G, B));
	}

	sf::Text Button::GetText() {
		return  m_text_for_button;
	}

}