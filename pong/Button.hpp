#pragma once
#include <SFML/Graphics.hpp>
#include "Logger.hpp"

namespace vg{
	struct PosButton
	{
		float x;
		float y;
	};
	class Button
	{

	private: // settings of button

		PosButton m_pos_button;
		std::unique_ptr<sf::RectangleShape> m_button;
		sf::Font m_font;
		std::string m_str = "";
		sf::Text m_text_for_button;

	public:

		Button(PosButton pos_button, std::string str);
		sf::RectangleShape* Get();
		void SetColorTextButton(int R, int G, int B);
		sf::Text GetText();

	};
}