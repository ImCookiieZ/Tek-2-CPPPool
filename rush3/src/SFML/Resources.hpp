//
// Created by benedikt on 1/23/21.
//

#ifndef RUSH3_RESOURCES_HPP
#define RUSH3_RESOURCES_HPP

#include <SFML/Graphics/Font.hpp>
#include "SFGraphing/SFPieChart.h"
#include "SFGraphing/SFPlot.h"
#include <SFML/Graphics/Color.hpp>
#include <vector>

class ColorScheme {
    public:
    ColorScheme( const sf::Color &outerBorder,
    sf::Color innerBorder,
    sf::Color headlineText, sf::Color minColor, sf::Color maxColor, sf::Color barColor,
    sf::Color windowBorder, sf::Color windowBackground
    ): OuterBorder(outerBorder), \
InnerBorder(innerBorder), HeadlineText(headlineText), MinColor(minColor), MaxColor(maxColor), BarColor(barColor) {};

    sf::Color OuterBorder;
    sf::Color InnerBorder;
    sf::Color HeadlineText;
    sf::Color MinColor;
    sf::Color MaxColor;
    sf::Color BarColor;
    sf::Color WindowBorder;
    sf::Color WindowBackground;
};

class Resources {
    public:
    sf::Font stdFont;
    std::vector<ColorScheme> themes;
    unsigned int cur_theme = 0;
    unsigned int totalThemes = 0;

     Resources(bool style)
    {
        ColorScheme ColorScheme1(sf::Color::Blue, sf::Color::Blue, sf::Color::White, sf::Color::Red, sf::Color::Green, sf::Color::Cyan, sf::Color::Transparent, sf::Color::Transparent);
        themes.push_back(ColorScheme1);
        totalThemes++;
        ColorScheme ColorScheme2(sf::Color(43, 43, 43, 255),
                                 sf::Color(169, 183, 198, 255),
                                 sf::Color(128, 128, 128, 255),
            sf::Color(128, 128, 169, 255), sf::Color(12, 122, 116, 255),
                                 sf::Color::Blue,
                                 sf::Color(169, 183, 198, 255),
                                 sf::Color(43, 43, 43, 255));
        themes.push_back(ColorScheme2);
        totalThemes++;

        if (style)
            cur_theme = 1;
        stdFont.loadFromFile("src/SFML/Bebas-Regular.otf");
    };

};

#endif //RUSH3_RESOURCES_HPP
