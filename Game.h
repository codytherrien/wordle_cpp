#pragma once
#include "WndInterface.h"
#include <random>
#include "WordDatabase.h"
#include "PlayHistory.h"

// Game class -> Manages intances of the game

class Game {
    public:
    // Initializes the game in the lobby
    Game(const sf::IntRect& gameBounds, const sf::Font& font);
    virtual ~Game();

    // Updates the current state of the active window.
    void update(const float deltaTime);

    // Draws the current window
    void draw(sf::RenderWindow& renderWindow) const;

    // Handles passing events on to the active interface.
    void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft);

    // Handles passing the mouse moved event to the active interface.
    void handleKeyInput(const sf::KeyboardKey key);

    // When true -> end game
    bool getGameCloseRequested();

    private:
    // Bounds of the game area.
    const sf::IntRect _bounds;

    // Reference to the font
    const sf::Font& _font;

    // Shared randomEngine used for randomization
    std::default_random_engine _randomEngine;

    // Reference to the current active overlay if one exists
    WndInterface* _activeInterface;

    // Reference to the current active overlay if exists
    WndInterface* _activeOverlay;

    // When true -> game ends
    bool _terminateGame;

    // Collection of words
    std::unique_ptr<WordDatabase> _wordDatabase;

    // Player's saves history
    std::unique_ptr<PlayHistory> _playHistory;
};