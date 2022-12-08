#pragma once
#include "WndInterface.h"
#include "Button.h"

class KeyboardWnd : public WndInterface {
    public:
        KeyboardWnd(const sf::IntRect& Bounds, const sf::Font& font);
        virtual ~KeyboardWnd() = default;

        virtual void update(const float deltaTime) override {};

        virtual void draw(sf::RenderWindow& renterWindow) const override;

        virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

        virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

        int getActionIDReset();

        void applyRules(std::vector<std::string> rules);

    private:
        // List of buttons on keyboard
        std::vector<Button> _buttons;

        // Current actionID
        int _actionID;

        // Initialises buttons
        void initialiseButtons(const sf::Font& font);
};