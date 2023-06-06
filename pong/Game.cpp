#include "Game.hpp"
#include "Shape.hpp"
#include "Ball.hpp"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <string>

		
namespace vg 
{
	Window::Window() {}

	void Window::setText(std::string str, float x, float y, int size) {
		m_font.loadFromFile("alg.ttf");
		m_str = str;
		m_text.setFont(m_font);
		m_text.setString(str);
		m_text.setCharacterSize(size);
		m_text.setPosition(x, y);
	}

	bool Window::getError() {
		return m_error;
	}

	void Window::setCaption(const std::string& caption) {
		m_caption = caption;
	}
	
	void Window::setResolution(int width, int high) {
		m_width = width;
		m_high = high;
	}
	void Window::setup() {
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_width, m_high), m_caption);
	}

	Window::~Window() {

	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Game::Game() {}

	void Game::runGame() {

		vg::Ball ball({ 240,350 }, { 3,-3 }, 15);
		vg::Rect rect({ 240,750 }, 3, 120, 25);

		while (m_window->isOpen())
		{

			sf::Event event;

			ball.move();
			ball.collision(rect.getPosX());
			rect.moveRect();


			while (m_window->pollEvent(event))
			{
				m_count = ball.GetCounter();
				setText("Score ", 10, 10, 30);

				if (!ball.GetCanPlay()) {
					rect.ChangeSpeed(0);

				}

				mousePos = sf::Mouse::getPosition(*m_window.get());
				m_button_back_to_menu.Get()->setFillColor(sf::Color(170, 0, 0));
				m_button_back_to_menu.SetColorTextButton(128, 140, 17);

				if (m_button_back_to_menu.Get()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {

					m_button_back_to_menu.Get()->setFillColor(sf::Color(90, 0, 0));
					m_button_back_to_menu.SetColorTextButton(128, 50, 17);

					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.key.code == sf::Mouse::Left) {
							vg::Log::Write(vg::LogType::Info, "Your Score is " + std::to_string(m_count));
							m_window->close();
						}
					}
				}

				if (event.type == sf::Event::Closed) {
					vg::Log::Write(vg::LogType::Info, "Your Score is " + std::to_string(m_count));
					m_window->close();
				}


			}
			m_window->clear();
			m_window->draw(m_text);
			m_window->draw(*rect.Get());
			m_window->draw(*ball.Get());
			if (!ball.GetCanPlay()) {
				m_window->draw(*m_button_back_to_menu.Get());
				m_window->draw(m_button_back_to_menu.GetText());
			}
			m_window->display();
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}

	void Game::setText(std::string str, float x, float y, int size) {
		
		m_font.loadFromFile("alg.ttf");
		m_str = str + std::to_string(m_count);
		m_text.setFont(m_font);
		m_text.setString(m_str);
		m_text.setCharacterSize(size);
		m_text.setPosition(x, y);

	}

	Game::~Game() {}

////////////////////////////////////////////////////////////////////////////////////////////

	Info::Info() {}

	void Info::runInfo() {
		font_for_tmp.loadFromFile("alg.ttf");
		tmp_text.setFont(m_font);
		tmp_text.setCharacterSize(24);

		m_file.open("log.txt");

		while (getline(m_file, tmp_str)) {
			if (tmp_str.find("[Info]", 0) != -1) {
				tmp_text.setString(tmp_str);
				tmp_text.setPosition(20, high);
				high += 30;
				try
				{
					if (number_of_strs >= 24) {
						m_error = 1;
						throw std::overflow_error("error, no memory for Info");
					}

					strings[number_of_strs++] = tmp_text;
				}
				catch (const std::overflow_error& ex)
				{
					vg::Log::Write(vg::LogType::Error,ex.what());
					break;
				}
				tmp_str = "";
			}
		}

		while (m_window->isOpen())
		{
			setText("Information", 180, 10, 40);
			sf::Event event;
			mousePos = sf::Mouse::getPosition(*m_window.get());
			while (m_window->pollEvent(event))
			{

				if (event.type == sf::Event::Closed) {
					m_window->close();
				}

				m_button_back.Get()->setFillColor(sf::Color(170, 0, 0));
				m_button_back.SetColorTextButton(128, 140, 17);

				if (m_button_back.Get()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {

					m_button_back.Get()->setFillColor(sf::Color(90, 0, 0));
					m_button_back.SetColorTextButton(128, 50, 17);

					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.key.code == sf::Mouse::Left) {
							m_window->close();
						}
					}
				}

			}

			m_window->clear();
			m_window->draw(m_text);
			for (int i = 0; i < number_of_strs; i++) {
				m_window->draw(strings[i]);
			}
			m_window->draw(*m_button_back.Get());
			m_window->draw(m_button_back.GetText());
			m_window->display();

		}

	}

	Info::~Info() {
		m_file.close();
	}

//////////////////////////////////////////////////////////

	Menu::Menu() {}

	void Menu::runMenu() {
		background.loadFromFile("background.png");
		sprite_for_back.setTexture(background);
		m_button_game.SetColorTextButton(128, 140, 17);
		m_button_info.SetColorTextButton(128, 140, 17);

		while (m_window->isOpen())
		{

			sf::Event event;
			mousePos = sf::Mouse::getPosition(*m_window.get());

			while (m_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					if (!getError()) {
						vg::Log::Write(vg::LogType::Error, "No errors");
					}
					m_window->close();
				}

				m_button_game.Get()->setFillColor(sf::Color(170, 0, 0));
				m_button_game.SetColorTextButton(128, 140, 17);


				if (m_button_game.Get()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {

					m_button_game.SetColorTextButton(128, 50, 17);
					m_button_game.Get()->setFillColor(sf::Color(90, 0, 0));


					if (event.type == sf::Event::MouseButtonPressed) {

						if (event.key.code == sf::Mouse::Left) {
							vg::Game game;
							game.setResolution(600, 800);
							game.setCaption("Pong");
							game.setup();
							game.runGame();
						}
					}
				}

				m_button_info.Get()->setFillColor(sf::Color(170, 0, 0));
				m_button_info.SetColorTextButton(128, 140, 17);

				if (m_button_info.Get()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {

					m_button_info.Get()->setFillColor(sf::Color(90, 0, 0));
					m_button_info.SetColorTextButton(128, 50, 17);

					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.key.code == sf::Mouse::Left) {
							vg::Info info;
							info.setResolution(600, 800);
							info.setCaption("Information");
							info.setup();
							info.runInfo();
						}
					}
				}

				m_button_exit.Get()->setFillColor(sf::Color(170, 0, 0));
				m_button_exit.SetColorTextButton(128, 140, 17);

				if (m_button_exit.Get()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {

					m_button_exit.Get()->setFillColor(sf::Color(90, 0, 0));
					m_button_exit.SetColorTextButton(128, 50, 17);

					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.key.code == sf::Mouse::Left) {
							if (!getError()) {
								vg::Log::Write(vg::LogType::Error, "No errors");
							}
							m_window->close();
						}
					}
				}
			}
			m_window->clear();
			m_window->draw(sprite_for_back);
			m_window->draw(*m_button_game.Get());
			m_window->draw(*m_button_info.Get());
			m_window->draw(*m_button_exit.Get());
			m_window->draw(m_button_game.GetText());
			m_window->draw(m_button_info.GetText());
			m_window->draw(m_button_exit.GetText());
			m_window->display();
		}
	}

	Menu::~Menu() {}
}