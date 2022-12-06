#pragma once
#include <vector>

class PlayHistory {
    public:
        PlayHistory(const std::string& saveFileName);
        virtual ~PlayHistory() = default;

        void InsertHistory(const int countToIncrement);

        void insertHistoryLoss();

        const std::vector<std::pair<int, int>>& getHistory() const;

        int getTotalPlayed() const;

        int getCurrentStreak() const;

        int getMaxStreak() const;

        int getWinPercent() const;

    private:
        std::vector<std::pair<int, int>> _playHistory;
        int _totalPlayed;
        int _totalWon;
        int _currentStreak;
        int _maxStreak;
        std::string _saveFileName;
        
        void loadFile();

        void saveFile();

        // Initialises default dataset with all 0s
        void initialiseDefault();
}