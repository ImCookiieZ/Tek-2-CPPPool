//
// Created by benedikt on 1/23/21.
//

#include "MonitorModule.hpp"

MonitorModule::MonitorModule(Displays *displays, Resources *resources)
{
    _yMax = displays->GetMax();
    _xMin = 0;
    _name = displays->GetName();
    _resources = resources;
    _displays = displays;
    switch (displays->Chart) {
    case Displays::PIECHART:
        _graphType = IMonitorModule::PIECHART;
        createMaxMinPieChartData();
        break;
    case Displays::DIAGRAM:
        _graphType = LINEGRAPH;
        createMaxMinPlotData();
        break;
    case Displays::BARCHART:
        _graphType = BARGRAPH;
        createMaxMinPlotData();
        break;
    default:
        _graphType = NONE;
        break;
    }
}

void MonitorModule::createMaxMinPieChartData()
{
    delete _pieChartData;

    _yAxis.push_back(_displays->GetActual());
    _xAxis.push_back(_collapsedTimeSinceCreation);
    _collapsedTimeSinceCreation += 0.5;
    std::vector<float> values = {_displays->GetActual(), _displays->GetMax() > _displays->GetActual() ? _displays->GetMax() - _displays->GetActual() : 0};
    std::vector<std::string> labels = {_displays->ActualString, _displays->MaxString};
    std::vector<sf::Color> colors = {\
_resources->themes[_resources->cur_theme].MinColor, _resources->themes[_resources->cur_theme].MaxColor};

    _pieChartData = new csrc::PieChartDataSet(values, labels\
, csrc::Representation::ABSOLUTE, colors);
}

void MonitorModule::createMaxMinPlotData()
{
    delete _plotData;

    if(_displays->GetActual() > _yMax) _yMax = _displays->GetActual();
    _yAxis.push_back(_displays->GetActual());
    _xAxis.push_back(_collapsedTimeSinceCreation);

    if ((_graphType == BARGRAPH && _yAxis.size() > 60) || (_graphType == LINEGRAPH && _yAxis.size() >= 180)) {
        _yAxis.clear();
        _xAxis.clear();
        _yMax = _displays->GetMax();
        _collapsedTimeSinceCreation = 0;
        /*_xAxis.erase(_xAxis.begin());
        _yAxis.erase(_yAxis.begin());
        for (auto it = _xAxis.begin(); it != _xAxis.end(); it++)
            *it -= 0.5;*/
    }
    _collapsedTimeSinceCreation += 0.5;
    _plotData = new csrc::PlotDataSet(_xAxis, _yAxis, \
_resources->themes[_resources->cur_theme].BarColor, _displays->GetName(), (_graphType == BARGRAPH ? csrc::PlottingType::BARS : csrc::PlottingType::LINE));
}

void MonitorModule::switchGraphType(IMonitorModule::GraphType newType)
{
}

void MonitorModule::updatePlot()
{
   /* _yAxis.push_back(_displays->Actual);
    _xAxis.push_back(_collapsedTimeSinceCreation);*/

    _plotData->SetDataValue((int) _collapsedTimeSinceCreation, sf::Vector2f(_displays->GetActual(), _collapsedTimeSinceCreation));
    _collapsedTimeSinceCreation += 0.5;
}
