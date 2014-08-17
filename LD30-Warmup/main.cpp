#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow window;
    window.create(sf::VideoMode(WIDTH,HEIGHT), "Untitled game", sf::Style::Titlebar | sf::Style::Close);

    //Text preparation
    sf::Font font;
    if(!font.loadFromFile("res/dungeon.ttf"))
        std::cout << "Font not found..." << std::endl;
    sf::String sentence;
    sf::Text text(sentence, font, 40);
    text.setColor(sf::Color(0, 0, 0));
    text.setStyle(sf::Text::Bold);

    //Texture prep
    sf::Texture texture;
    if (!texture.loadFromFile("res/bg.png"))
        std::cout << "Texture not found..." << std::endl;
    sf::Sprite sprite;
    sprite.setTexture(texture);
    //Stretching image to fill screen
    sprite.setScale(WIDTH/sprite.getLocalBounds().width, HEIGHT/sprite.getLocalBounds().height);

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

                    break;
                case sf::Event::TextEntered:
                    if(event.text.unicode >= 32 && event.text.unicode <= 128){
                        sentence += (char)event.text.unicode;
                    }
                    else if((char)event.text.unicode == '\b' && sentence.getSize() > 0){
                        sentence.erase(sentence.getSize() - 1, sentence.getSize());
                    }

                    text.setString(sentence);

                    std::cout << text.getGlobalBounds().width << "/" << text.getGlobalBounds().height << std::endl;

                    break;
            }
        }

        window.draw(sprite);
        window.draw(text);
        window.display();
        window.clear();
    }
}
