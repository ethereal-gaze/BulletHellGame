#pragma once
#include <SFML/System.hpp>

// All environment data that object AI may need
struct EnvironmentData
{
    sf::Vector2i cursorPosition;
    sf::Vector2f playerPosition;

    EnvironmentData(sf::Vector2f playerPosition = sf::Vector2f(0, 0), sf::Vector2f cursorPosition = sf::Vector2f(0, 0)) :
                    cursorPosition(cursorPosition), playerPosition(playerPosition)
                    {};
};
