//
// Created by benedikt on 1/23/21.
//

#ifndef RUSH3_MONITORDISPLAY_HPP
#define RUSH3_MONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Resources.hpp"

class MonitorDisplay : public IMonitorDisplay {
    public:
    MonitorDisplay(sf::Vector2f size, sf::Vector2f position, \
IMonitorModule *module, Resources *resources);

    bool resizeAndMoveDisplay(sf::Vector2f newSize, sf::Vector2f newPosition
    ) override;
    void updateInformation() override;
    void drawAllElements(sf::RenderWindow *drawTo) override;
};
#endif //RUSH3_MONITORDISPLAY_HPP
