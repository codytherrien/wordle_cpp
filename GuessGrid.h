#pragma once
#include "WndInterface.h"
#include "PuzzleLetter.h"

class GuessGrid : public WndInterface {
    public:
        GuessGrid(
            const sf::IntRect& bounds,
            const sf::Font& font, 
            const std::string& solution,
            const int maxGuesses
        );
        virtual ~GuessGrid() = default;

        virtual void update(const float deltaTime) override {};
        
        virtual void draw(sf::RenderWindow& renderWindow) const override;

        virtual void handleKeyInput(const sf::Keyboard::Key key) override;

        void tryInsertLetter(const char letter);

        void backSpace();

        void checkSolution();

        bool isSolved() const;

        bool hasMoreGuesses() const;

        std::vector<std::string> getAllRules() const;

        bool getKeyCheckReset();

        std::string getSolution() const;

        std::string getShareString() const;

    private:
        std::vector<std::vector<PuzzleLetter>> _guessLetters;
        int _insertPosition;
        int _currentWordIndex;
        bool _solved;
        bool _usedKeyCheck;
        const std::string _solution;

        void initialiseAllGuesses(const sf::Font& font, const int wordLength, const int maxGuesses);
};