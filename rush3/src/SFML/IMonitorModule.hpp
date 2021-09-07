//
// Created by benedikt on 1/23/21.
//

#ifndef RUSH3_IMONITORMODULE_HPP
#define RUSH3_IMONITORMODULE_HPP

#include "SFGraphing/SFPlot.h"
#include "SFGraphing/SFPieChart.h"
#include "../Displays.hpp"
#include "Resources.hpp"

class IMonitorModule {
    public:
    enum MonitorType {
        PERCANTAGE,
        TEXTONLY,
        NUMBERONLY
    };
    enum GraphType {
        NONE,
        PIECHART,
        LINEGRAPH,
        BARGRAPH
    };
    virtual ~IMonitorModule() = default;
    virtual void createMaxMinPieChartData() = 0 ;
    virtual void createMaxMinPlotData() = 0;
    virtual void updatePlot() = 0;

    virtual void switchGraphType(GraphType newType) = 0;


    MonitorType _monitorType;
    GraphType _graphType;

    std::vector<float> _yAxis;
    std::vector<float> _xAxis;
    float _yMax;
    float _xMin = 0;
    float _collapsedTimeSinceCreation = 0;

    csrc::PieChartDataSet *_pieChartData = nullptr;
    csrc::PlotDataSet *_plotData = nullptr;

    Displays *_displays = nullptr;
    Resources *_resources = nullptr;

    std::string _name;
};

#endif //RUSH3_IMONITORMODULE_HPP
