#include "SFGraphing/SFPlot.h"
#include "SFGraphing/SFPieChart.h"
#include <vector>
#include <string>

#include "Resources.hpp"
#include "MonitorModule.hpp"
#include "MonitorDisplay.hpp"

#include "../Displays.hpp"
#include "../CpuMhzInfo.hpp"
#include "../User.hpp"
#include "../getSystemData/SystemGetter.hpp"
#include "../RamInfos.hpp"
#include "../NetworkData.hpp"
#include "../SwapInfos.hpp"
#include "../CpuPercentage.hpp"

int mainSFML(bool style)
{
    User userInfos;
    SwapInfos swapInfos;
    CpuPercentageInfos cpuPercentageInfos(0);
    CpuMhzInfo cpuMhzInfo(0);
    RamInfos ramInfos;
    NetworkData networkData;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(1920, 1200), "Rush3", sf::Style::Default, settings);
    Resources resources(style);


    MonitorModule monitorModuleUser(&userInfos, &resources);
    MonitorModule monitorModuleNetwork(&networkData, &resources);
    MonitorModule monitorModuleSwap(&swapInfos, &resources);
    MonitorModule monitorModuleCpuPercantage(&cpuPercentageInfos, &resources);
    MonitorModule monitorModuleCpu(&cpuMhzInfo, &resources);
    MonitorModule monitorModuleRam(&ramInfos, &resources);

   MonitorDisplay monitorDisplayUser(sf::Vector2f(window.getSize().x * 0.30, window.getSize().y * 0.30), sf::Vector2f(10, 20),
        &monitorModuleUser, &resources);
   MonitorDisplay monitorDisplayNetwork(sf::Vector2f(window.getSize().x * 0.65, window.getSize().y * 0.30), sf::Vector2f(650, 20),
    &monitorModuleNetwork, &resources);
   MonitorDisplay monitorDisplaySwap(sf::Vector2f(window.getSize().x * 0.40, window.getSize().y * 0.25), sf::Vector2f(10, 410), &monitorModuleSwap, &resources);
   MonitorDisplay monitorDisplayCpuPercantage(sf::Vector2f(window.getSize().x * 0.56, window.getSize().y * 0.25), sf::Vector2f(825, 410), &monitorModuleCpuPercantage, &resources);
   MonitorDisplay monitorDisplayRam(sf::Vector2f(window.getSize().x * 0.40, window.getSize().y * 0.33), sf::Vector2f(10, 670), &monitorModuleRam, &resources);
   MonitorDisplay monitorDisplayCpu(sf::Vector2f(window.getSize().x * 0.56, window.getSize().y * 0.33), sf::Vector2f(825, 670), &monitorModuleCpu, &resources);

   while (window.isOpen())
   {
       sf::Event event;
       if (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
           {
               window.close();
           } else if (event.type == sf::Event::Resized) {
               monitorDisplayUser.resizeAndMoveDisplay(sf::Vector2f(window.getSize().x * 0.30, window.getSize().y * 0.30), sf::Vector2f(10, 20));
               monitorDisplayNetwork.resizeAndMoveDisplay(sf::Vector2f(window.getSize().x * 0.65, window.getSize().y * 0.30), sf::Vector2f(650, 20));
               monitorDisplaySwap.resizeAndMoveDisplay(sf::Vector2f(window.getSize().x * 0.40, window.getSize().y * 0.25), sf::Vector2f(10, 410));
               monitorDisplayCpuPercantage.resizeAndMoveDisplay(sf::Vector2f(window.getSize().x * 0.56, window.getSize().y * 0.25), sf::Vector2f(825, 410));
                  monitorDisplayRam.resizeAndMoveDisplay(sf::Vector2f(window.getSize().x * 0.40, window.getSize().y * 0.33), sf::Vector2f(10, 670));
               monitorDisplayCpu.resizeAndMoveDisplay(sf::Vector2f(window.getSize().x * 0.56, window.getSize().y * 0.33), sf::Vector2f(825, 670));
           }
       }

       window.clear(sf::Color(30, 30, 30));
       monitorDisplayUser.drawAllElements(&window);
       monitorDisplayNetwork.drawAllElements(&window);
       monitorDisplaySwap.drawAllElements(&window);
       monitorDisplayCpuPercantage.drawAllElements(&window);
       monitorDisplayCpu.drawAllElements(&window);
       monitorDisplayRam.drawAllElements(&window);

       window.display();
   }

   return 0;
}
