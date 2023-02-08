#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>



class AnimatedText 
{
private:
    std::string m_text;
    double m_duration;
    std::vector <std::string> m_split_text;
    
public:
    AnimatedText(const int& duration, const std::string& text)
    {
        m_duration = duration;
        m_text = text;
    }
    void SetText()
    {
        for (int i = 1; i < m_text.length(); i++) {
            m_split_text.push_back(m_text.substr(0, i));
        }

    }
    double GetPace()
    {
        double pace = m_duration / m_text.length();
        return pace;
    }
    std::string GetText()
    {
        if (m_split_text.size() == 0) {
            return m_text;
        }
        std::string temp_text = m_split_text.front();
        m_split_text.erase(m_split_text.begin());
        return temp_text;
    
    }


};


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::Clock clock;
   
    AnimatedText Atext(13, "Hello, world!");
    Atext.SetText();
    
     sf::Font font;
    font.loadFromFile("alg.ttf");
    sf::Text text;
    text.setCharacterSize(45);
    text.setFont(font);
    text.setColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        if (clock.getElapsedTime().asSeconds() >= Atext.GetPace()) {
            text.setString(Atext.GetText());
            clock.restart();
        }
        window.draw(text);
        window.display();
        
    }

    return 0;
}