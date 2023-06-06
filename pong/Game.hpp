#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "Ball.hpp"
#include "Shape.hpp"
#include <chrono>
#include <thread>
#include "Logger.hpp"
#include <memory>
namespace vg

{
	class Window
	{
	private:
		int m_width=0, m_high=0;
		std::string m_caption ="";
		
	protected:
		bool m_error = 0;
		sf::Font m_font;
		std::string m_str = "";
		sf::Text m_text;
		std::unique_ptr<sf::RenderWindow> m_window;   // smart pointer
		sf::Vector2i mousePos;

	public:

		Window();

		virtual void setText(std::string str, float x, float y, int size);

		virtual bool getError();

		void setCaption(const std::string& caption);

		void setResolution(int width, int high);

		void setup();

		virtual ~Window();

	};

	class Game : public Window
	{
	private:
		int m_count=0;
		vg::Button m_button_back_to_menu{ {225,300}, "Menu" };

	public:

		Game();

		void runGame();

		void setText(std::string str, float x, float y, int size);

		~Game();

	};

	class Info : public Window
	{
	private:
		std::ifstream m_file; 
		sf::Text tmp_text;                                                         // for file 
		sf::Font font_for_tmp;                                                     //
		std::string tmp_str = "";                                                  //
		int high = 60;	                                                           //
		int number_of_strs=0;                                                      //
		                                                                            
		std::unique_ptr<sf::Text[]> strings = std::make_unique<sf::Text[]>(24);    // smart pointer

		vg::Button m_button_back{ {30,720}, "Back" };

	public:

		Info();

		void runInfo();

		~Info();

	};

	class Menu : public Window
	{
	private:
		sf::Sprite sprite_for_back;
		sf::Texture background;
		vg::Button m_button_game{ {225,200}, "Play"};
		vg::Button m_button_info{ {225,300}, "Info"};
		vg::Button m_button_exit{ {225,600}, "Exit" };

	public:

		Menu();

		void runMenu();

		~Menu();

	};

}