#pragma once
#include "WndInterface.h"
#include "KeyboardWnd.h"
#include "GuessGrid.h"


class PuzzleWnd : public WndInterface {
    public:
        // Initializes puzzle with a new puzzle
        PuzzleWnd(const sf::IntRect& bounds, const sf::Font& font, const std::string& solution);
        virtual ~PuzzleWnd();

        // Updates the current state of the window
        virtual void update(const float deltaTime) override;

        // Draws all the componenets of the PuzzleWnd
        virtual void draw(sf::RenderWindow& renterWindow) const override;

        virtual void handleMousePress(const sf::Vector2i& moustPosition, bool isLeft) override;

        virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

        virtual void handleKeyInput(const sf::Keyboard::Key key) override;

        const GuessGrid& getGuessGrid() const;

        // Gets the state to check if the window is requestion an action
        WndResultState getResultState() const override;

    private:
        // Font used for the window
        const sf::Font& _font;

        // Title text
        sf::Text _gameTitle;

        //Author text
        sf::Text _author;

        // Keyboard used for input
        KeyboardWnd _keyboard;

        // Grid of guesses where the keyboard input goes
        GuessGrid _guessGrid;

        // Current state of this window. Changes to finished when ready to close
        WndResultState _currentState;
};