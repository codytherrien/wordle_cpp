#pragma once
#include "HistogramBar.h"
#include <vector>

class HorizontalHistogram {
    public:
        HorizontalHistogram(
            const sf::IntRect& bounds,
            const sf::Font& font,
            const std::vector<std::pair<int, int>> data,
            const int highlightIndex
        );
        virtual ~HorizontalHistogram() = default;

        void draw(sf::RenderWindow& renderWindow) const;

    private:
    std::vector<std::unique_ptr<HistogramBar>> _bars;
};