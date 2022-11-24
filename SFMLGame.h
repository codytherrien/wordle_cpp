#pragma once
#include "Game.h"

/*
SFMLGame class:
Manages the sf::RenderWindow and game loop by passing info to the Game Class.
*/
class SFMLGame {
    public:
    // Initializes game
    SFMLGame();
    virtual ~SFMLGame() = default;

    // Continues running the game
    void gameLoop();

    private:
    // The window used for the game
    sf::RenderWindow _window;

    // The font used in the game
    sf::Font _font

    // Reference to the game used to manage interactions within the game
    Game _game;

    // Loads font
    static sf::Font loadFont():
}