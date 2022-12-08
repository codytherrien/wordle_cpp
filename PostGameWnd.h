#pragma once
#include "WndInterface.h"
#include "Button.h"
#include "HorizontalHistogram.h"
#include "PlayHistory.h"

class PostGameWnd : public WndInterface {
    public:
        PostGameWnd(
            const sf::IntRect& bounds,
            const sf::Font& font,
            const std::string& solution,
            const bool wonGame,
            const int attempts,
            const std::unique_ptr<PlayHistory>& playHistory,
            const std::string& shareStr
        );
        virtual ~PostGameWnd() = default;

        virtual void update(const float deltaTime) override {};

        virtual void draw(sf::RenderWindow& renderWindow) const override;

        virtual void handleMousePress(
            const sf::Vector2i& mousePosition,
            bool isLeft
        ) override;

        virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

        WndResultState getResultState() const override;

    private:
        WndResultState _resultState;
        std::vector<Button> _buttons;
        std::unique_ptr<sf::RectangleShape> _background;
        std::unique_ptr<sf::RectangleShape> _fullScreenBackground;
        std::unique_ptr<sf::Text> _titleText;
        std::unique_ptr<sf::Text> _solutionText;
        std::unique_ptr<HorizontalHistogram> _histogram;
        std::unique_ptr<sf::Text> _totalPlayedText;
        std::unique_ptr<sf::Text> _winPercentText;
        std::unique_ptr<sf::Text> _currentStreakText;
        std::unique_ptr<sf::Text> _maxStreakText;
        std::string _shareStr;
};