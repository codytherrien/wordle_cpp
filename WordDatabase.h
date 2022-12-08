#pragma once

#include <vector>
#include <random>

class WordDatabase {
    public:
        // Initializes word database with the associated file
        WordDatabase(std::default_random_engine &randomEngine);
        virtual ~WordDatabase() = default;

        // Returns tru if the word specified is a word in the database
        bool isValidWord(const std::string &word) const;

        //Returns random word from database
        std::string getRandomWord() const;

    private:
        // Database of words
        std::vector<std::string> _words;

        // Shared randomEngine used for all randomization
        std::default_random_engine& _randomEngine;

        // Loads the word list in and sorts in alphabetically
        void loadDatabase();
};