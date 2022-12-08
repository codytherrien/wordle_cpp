#pragma once
#include <SFML/Graphics.hpp>

class PuzzleLetter {
    public:
        enum SolutionState {NO_STATE, CORRECT, WRONG_POS};

        PuzzleLetter(const sf::IntRect& bounds, const sf::Font& font);
        virtual ~PuzzleLetter() = default;

        void draw(sf::RenderWindow& renderWindow) const;

        char getLetter() const;

        void setLetter(const char letter);

        void setSolutionState(const SolutionState& solutionState);

        SolutionState getSolutionState() const;

    private:
        sf::IntRect _bounds;
        char _letter;
        sf::RectangleShape _background;
        sf::Text _textVisual;
        SolutionState _currentState;

        void setBackgroundColour(const sf::Color& colour);
};