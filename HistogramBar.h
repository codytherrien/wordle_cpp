#pragma once
#include <SFML/Graphics.hpp>

class HistogramBar {
    public:
        HistogramBar(
            const sf::IntRect& bounds,
            const sf::Font& font,
            const int title,
            const int value,
            const int max
        );
        virtual ~HistogramBar() = default;

        void draw(sf::RenderWindow& renderWindow) const;
        void setBarColour(const sf::Color& colour);

    private:
        std::unique_ptr<sf::Text> _titleText;
        std::unique_ptr<sf::RectangleShape> _bar;
        std::unique_ptr<sf::Text> _valueText;
};