#pragma once
#include <SFML/Graphics.hpp>

class Button {
    public:
        Button(const sf::IntRect& bounds, const std::string& text, const int actionID, const sf::Font& font);
        virtual ~Button() = default;

        void draw(sf::RenderWindow& renderWindow) const;

        int getActionID() const;

        void setHovering(const bool isHovering);

        bool isPositionInside(const sf::Vector2i& mousePosition) const;

        void setBackgroundColour(const sf::Color& colour);

        void applyColourID(const int colourID);

    private:
        // Bounds of the rectangle used for isPositionInside
        sf::IntRect _bounds;
        int _actionID;
        bool _isHovered;
        std::string _text;
        sf::RectangleShape _background;
        sf::Text _textVisual;
        int _colourID;
};