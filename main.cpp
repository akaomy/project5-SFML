#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(900, 900), "My window");
    window.setFramerateLimit(60);
    std::cout << "Game Started" << std::endl;

    sf::RectangleShape rect(sf::Vector2f(200, 200));
    rect.setFillColor(sf::Color::White);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(2);
    rect.setOrigin(0, 0);
    rect.setPosition(sf::Vector2f(400, 300));

    sf::CircleShape circle(50, 200);
    circle.setFillColor(sf::Color::Green);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(2);
    circle.setPosition(sf::Vector2f(400, 300));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // logic handling
        circle.move(sf::Vector2f(0, 0.5f));
        circle.rotate(2);
        rect.move(sf::Vector2f(0, 0.5f));
        rect.rotate(1);

        // clear the window with black color
        window.clear(sf::Color{200, 200, 200});

        // draw everything here...
        window.draw(circle);
        window.draw(rect);

        // end the current frame
        window.display();
    }

    return 0;
}
