#pragma once
#include "Shape.hpp"
#include <SFML/Graphics.hpp>
namespace vg 
{
	struct PosCircle
	{
		float x;
		float y;
	};
	struct SpeedCircle
	{
		float x;
		float y;
	};
	class Ball
	{
	private:
		sf::Texture m_texture;
		PosCircle m_posCir;
		SpeedCircle m_speedCir;
		float m_radius;
		
		std::unique_ptr<sf::CircleShape> m_circle;
		unsigned int m_counter = 0;
		bool CanPlay = 1;

	public:

		Ball(PosCircle posCir, SpeedCircle speedCir, float radius);
		bool& GetCanPlay();
		void move();
		void collision(float x);
		unsigned int& GetCounter();
		sf::CircleShape* Get();
		~Ball();

	};
}
