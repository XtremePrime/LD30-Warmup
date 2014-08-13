#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(800,600), "Untitled Project", sf::Style::Titlebar | sf::Style::Close);

    while(window.isOpen())
    {
         sf::Event event;
         while(window.pollEvent(event))
         {
             if(event.type == sf::Event::Closed)
                 window.close();
         }
         window.display();
    }
}
