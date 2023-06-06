#pragma once
#include <SFML/Graphics.hpp>
namespace vg
{

	struct PosRect

	{
		float x;
		float y;
	};

	class Rect

	{

	private:

		PosRect m_posRect;
		float m_speedRect;
		std::unique_ptr<sf::RectangleShape> rect;
		float m_width;
		float m_high;
		sf::Texture m_texture;

	public:

		Rect(PosRect posR, float Speed, float width, float high);
		~Rect();
		void ChangeSpeed(float new_speed);
		void moveRect();
		float& getPosX();
		sf::RectangleShape* Get();
	};

}