#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(800,600), "Untitled game", sf::Style::Titlebar | sf::Style::Close);

    //Text preparation
    sf::Font font;
    if(!font.loadFromFile("dungeon.ttf"))
        std::cout << "Font not found..." << std::endl;
    sf::String sentence;
    sf::Text text(sentence, font, 40);
    text.setColor(sf::Color(255, 0, 0));
    text.setStyle(sf::Text::Bold);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Escape)
                        window.close();
                    if(event.key.code == sf::Keyboard::Return)
                        sentence += "\n";

                case sf::Event::TextEntered:
                    if(event.text.unicode >= 32 && event.text.unicode <= 126)
                        sentence += (char)event.text.unicode;
                    else if(event.text.unicode == 8 && sentence.getSize() > 0)
                        sentence.erase(sentence.getSize() - 1, sentence.getSize());

                    // if(text.getLocalBounds().width >= 550)
                    //     sentence += "\n";

                    text.setString(sentence);


                    break;
            }
        }
        window.draw(text);
        window.display();
        window.clear();
    }
}
