//
// Created by benedikt on 1/23/21.
//

#ifndef RUSH3_MONITORMODULE_HPP
#define RUSH3_MONITORMODULE_HPP

#include "IMonitorModule.hpp"
#include "Resources.hpp"

class MonitorModule : public IMonitorModule {
    public:
    MonitorModule(Displays *displays, Resources *resources);

    void createMaxMinPieChartData() override;
    void createMaxMinPlotData() override;
    void updatePlot() override;

    void switchGraphType(GraphType newType) override;
};

#endif //RUSH3_MONITORMODULE_HPP
