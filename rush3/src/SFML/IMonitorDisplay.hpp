//
// Created by benedikt on 1/23/21.
//

#ifndef RUSH3_IMONITORDISPLAY_HPP
#define RUSH3_IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include "MonitorModule.hpp"
#include "Resources.hpp"

class IMonitorDisplay {
    public:
    virtual ~IMonitorDisplay() = default;

    virtual bool resizeAndMoveDisplay(sf::Vector2f newSize,
        sf::Vector2f newPosition
    ) = 0;
    virtual void updateInformation() = 0;


    virtual void drawAllElements(sf::RenderWindow *drawTo) = 0;

    IMonitorModule *_monitorModule;
    sf::Text _headlineText;
    sf::Vector2f _size;

    protected:
    csrc::SFPieChart *_pieChart = nullptr;
    csrc::SFPlot *_plot = nullptr;
    sf::Vector2f _position;
    sf::RectangleShape _outline;
    sf::RectangleShape _innerOutline;

    sf::Text _text1;
    sf::Text _text2;
    sf::Text _text3;

    sf::Clock _informationRequestClock;
    float _informationRequestRefreshRate;
    sf::Window _window;
};

#endif //RUSH3_IMONITORDISPLAY_HPP
