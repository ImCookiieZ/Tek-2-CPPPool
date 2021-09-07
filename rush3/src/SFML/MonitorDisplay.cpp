//
// Created by benedikt on 1/23/21.
//

#include "SFGraphing/SFPlot.h"
#include "SFGraphing/SFPieChart.h"
#include "MonitorDisplay.hpp"


MonitorDisplay::MonitorDisplay(sf::Vector2f size, sf::Vector2f position,
    IMonitorModule *module, Resources *resources)
{
    _informationRequestClock.restart();
    _informationRequestRefreshRate = 0.5f;
    _position = position;
    _size  = size;
    _monitorModule = module;

    _headlineText.setString(_monitorModule->_name);
  //  _headlineText.setCharacterSize( /*size.y < size.x ? (unsigned int) size.y * 0.10 :*/ (unsigned int) size.y * 0.10);
    _headlineText.setFont(resources->stdFont);
    _headlineText.setPosition(sf::Vector2f(_position.x + 1, _position.y - 1));
    _headlineText.setFillColor(resources->themes[resources->cur_theme].HeadlineText);

    _outline.setSize(size);
    _outline.setPosition(position);
    _outline.setFillColor(resources->themes[resources->cur_theme].WindowBorder);
    _outline.setOutlineColor(resources->themes[resources->cur_theme].OuterBorder);
    _outline.setOutlineThickness(1);
    _innerOutline.setSize(sf::Vector2f(size.x * 0.95, size.y * 0.90));
    _innerOutline.setPosition(sf::Vector2f(\
position.x + (_outline.getSize().x - _innerOutline.getSize().x) / 2, \
position.y + (_outline.getSize().y -  _innerOutline.getSize().y) / 2));
    _innerOutline.setFillColor(resources->themes[resources->cur_theme].WindowBackground);
    _innerOutline.setOutlineColor(resources->themes[resources->cur_theme].InnerBorder);
    _innerOutline.setOutlineThickness(1);

    _headlineText.setCharacterSize((_outline.getSize().y - _innerOutline.getSize().y) / 2);

    switch (_monitorModule->_graphType ) {
    case IMonitorModule::NONE:
        break;
    case IMonitorModule::PIECHART:
        if (_monitorModule->_pieChartData)
            _pieChart = new csrc::SFPieChart(_monitorModule->_pieChartData, \
sf::Vector2f(_position.x + _size.x * 0.95 - (_size.x < _size.y ? _size.x / 6 : _size.y / 6) - \
(std::to_string((int) _monitorModule->_displays->GetMax()).length() + _monitorModule->_displays->MaxString.length() \
> std::to_string((int) _monitorModule->_displays->GetActual()).length() + _monitorModule->_displays->ActualString.length() ? \
std::to_string((int) _monitorModule->_displays->GetMax()).length() + _monitorModule->_displays->MaxString.length() + 3 : \
std::to_string((int) _monitorModule->_displays->GetActual()).length() + _monitorModule->_displays->ActualString.length() + 3) * _headlineText.getCharacterSize(), _position.y + _size.y  * 0.5), \
_size.x < _size.y ? _size.x / 3 : _size.y / 3, &_monitorModule->_resources->stdFont);
        _pieChart->GenerateVertices();
        break;
    case IMonitorModule::BARGRAPH:
        _plot = new csrc::SFPlot(\
sf::Vector2f(_innerOutline.getPosition().x + _innerOutline.getSize().x / 2.2, _innerOutline.getPosition().y),\
sf::Vector2f(_innerOutline.getSize().x / 2, _innerOutline.getSize().y), \
40.0f, &resources->stdFont, "elapsed Time", _monitorModule->_displays->Y_Name);
        _plot->AddDataSet(_monitorModule->_plotData);
        _plot->SetupAxes(0, 0.5, 0, _monitorModule->_yMax, 0.5, _monitorModule->_yMax / 10, resources->themes[resources->cur_theme].BarColor);
        _plot->GenerateVertices();
        break;
    case IMonitorModule::LINEGRAPH:
        delete _plot;
        _plot = new csrc::SFPlot(\
sf::Vector2f(_innerOutline.getPosition().x + _innerOutline.getSize().x / 2.2, _innerOutline.getPosition().y),\
sf::Vector2f(_innerOutline.getSize().x / 2, _innerOutline.getSize().y), \
40.0f, &resources->stdFont, "elapsed Time", _monitorModule->_displays->Y_Name);
        _plot->AddDataSet(_monitorModule->_plotData);
        _plot->SetupAxes(0, 0.5, 0, _monitorModule->_yMax, 0.5, _monitorModule->_yMax / 10, resources->themes[resources->cur_theme].BarColor);
        _plot->GenerateVertices();
        break;
    default:
        break;
    }

    _text1.setString(_monitorModule->_displays->GetString1());
    _text1.setFont(resources->stdFont);
    _text1.setPosition(sf::Vector2f(_innerOutline.getPosition().x + 10, _innerOutline.getPosition().y - 1));
    unsigned int longestTextCharCount = _monitorModule->_displays->GetString1().length() > \
_monitorModule->_displays->GetString2().length() ? _monitorModule->_displays->GetString1().length() : _monitorModule->_displays->GetString2().length();
    if (longestTextCharCount < _monitorModule->_displays->GetString3().length()) longestTextCharCount = _monitorModule->_displays->GetString3().length();
    _text1.setCharacterSize(_innerOutline.getSize().x / longestTextCharCount * (_monitorModule->_graphType == IMonitorModule::NONE ? 2 : 1));
    if (longestTextCharCount  * 3 > _innerOutline.getSize().y) _text1.setCharacterSize(_innerOutline.getSize().y / 3);
    if (longestTextCharCount == 1)
        _text1.setCharacterSize(size.x / 10);
    _text2 = _text1;
    _text2.setString(_monitorModule->_displays->GetString2());
    _text2.move(0, _text1.getCharacterSize());
    _text3 = _text2;
    _text3.setString(_monitorModule->_displays->GetString3());
    _text3.move(0, _text1.getCharacterSize());
}

bool MonitorDisplay::resizeAndMoveDisplay(sf::Vector2f newSize,
    sf::Vector2f newPosition
)
{
    _position = newPosition;
    _size  = newSize;

    _headlineText.setPosition(sf::Vector2f(_position.x + 1, _position.y - 1));

    _outline.setSize(_size);
    _outline.setPosition(_position);
    _innerOutline.setSize(sf::Vector2f(_size.x * 0.95, _size.y * 0.90));
    _innerOutline.setPosition(sf::Vector2f(\
_position.x + (_outline.getSize().x - _innerOutline.getSize().x) / 2, \
_position.y + (_outline.getSize().y -  _innerOutline.getSize().y) / 2));

    _headlineText.setCharacterSize((_outline.getSize().y - _innerOutline.getSize().y) / 2);

    switch (_monitorModule->_graphType ) {
    case IMonitorModule::NONE:
        break;
    case IMonitorModule::PIECHART:
        if (_monitorModule->_pieChartData)
            _pieChart = new csrc::SFPieChart(_monitorModule->_pieChartData, \
sf::Vector2f(_position.x + _size.x * 0.95 - (_size.x < _size.y ? _size.x / 6 : _size.y / 6) - \
(std::to_string((int) _monitorModule->_displays->GetMax()).length() + _monitorModule->_displays->MaxString.length() \
> std::to_string((int) _monitorModule->_displays->GetActual()).length() + _monitorModule->_displays->ActualString.length() ? \
std::to_string((int) _monitorModule->_displays->GetMax()).length() + _monitorModule->_displays->MaxString.length() + 3 : \
std::to_string((int) _monitorModule->_displays->GetActual()).length() + _monitorModule->_displays->ActualString.length() + 3) * _headlineText.getCharacterSize(), _position.y + _size.y  * 0.5), \
_size.x < _size.y ? _size.x / 3 : _size.y / 3, &_monitorModule->_resources->stdFont);
        _pieChart->GenerateVertices();
        break;
    case IMonitorModule::BARGRAPH:
        _plot = new csrc::SFPlot(\
sf::Vector2f(_innerOutline.getPosition().x + _innerOutline.getSize().x / 2.2, _innerOutline.getPosition().y),\
sf::Vector2f(_innerOutline.getSize().x / 2, _innerOutline.getSize().y), \
40.0f, &_monitorModule->_resources->stdFont, "elapsed Time", _monitorModule->_displays->Y_Name);
        _plot->AddDataSet(_monitorModule->_plotData);
        _plot->SetupAxes(0, 0.5, 0, _monitorModule->_yMax, 0.5, _monitorModule->_yMax / 10, _monitorModule->_resources->themes[_monitorModule->_resources->cur_theme].BarColor);
        _plot->GenerateVertices();
        break;
    case IMonitorModule::LINEGRAPH:
        delete _plot;
        _plot = new csrc::SFPlot(\
sf::Vector2f(_innerOutline.getPosition().x + _innerOutline.getSize().x / 2.2, _innerOutline.getPosition().y),\
sf::Vector2f(_innerOutline.getSize().x / 2, _innerOutline.getSize().y), \
40.0f, &_monitorModule->_resources->stdFont, "elapsed Time", _monitorModule->_displays->Y_Name);
        _plot->AddDataSet(_monitorModule->_plotData);
        _plot->SetupAxes(0, 0.5, 0, _monitorModule->_yMax, 0.5, _monitorModule->_yMax / 10, _monitorModule->_resources->themes[_monitorModule->_resources->cur_theme].BarColor);
        _plot->GenerateVertices();
        break;
    default:
        break;
    }

    _text1.setPosition(sf::Vector2f(_innerOutline.getPosition().x + 10, _innerOutline.getPosition().y - 1));
    unsigned int longestTextCharCount = std::string(_text1.getString()).length() > \
std::string(_text2.getString()).length() ? std::string(_text1.getString()).length() : std::string(_text2.getString()).length();
    if (longestTextCharCount < std::string(_text3.getString()).length()) longestTextCharCount = std::string(_text3.getString()).length();
    _text1.setCharacterSize(_innerOutline.getSize().x / longestTextCharCount);
    if (longestTextCharCount  * 4 > _innerOutline.getSize().y) _text1.setCharacterSize(_innerOutline.getSize().y / 4);
    _text2 = _text1;
    _text2.setString(_monitorModule->_displays->GetString2());
    _text2.move(0, _text1.getCharacterSize());
    _text3 = _text2;
    _text3.setString(_monitorModule->_displays->GetString3());
    _text3.move(0, _text1.getCharacterSize());
    return true;
}


void MonitorDisplay::drawAllElements(sf::RenderWindow *drawTo)
{
    updateInformation();
    drawTo->draw(_outline);
    drawTo->draw(_innerOutline);
    switch (_monitorModule->_graphType ) {
    case IMonitorModule::NONE:
        break;
    case IMonitorModule::PIECHART:
        drawTo->draw(*_pieChart);
        break;
    case IMonitorModule::BARGRAPH:
        drawTo->draw(*_plot);
        break;
    case IMonitorModule::LINEGRAPH:
        drawTo->draw(*_plot);
    default:
        break;

    }
    drawTo->draw(_headlineText);
    if (_text1.getString() != "")
        drawTo->draw(_text1);
    if (_text2.getString() != "")
        drawTo->draw(_text2);
    if (_text3.getString() != "")
        drawTo->draw(_text3);
}

void MonitorDisplay::updateInformation()
{
    if (_informationRequestClock.getElapsedTime().asSeconds() >= _informationRequestRefreshRate) {
        _informationRequestClock.restart();
            switch (_monitorModule->_graphType ) {
            case IMonitorModule::PIECHART:
                _monitorModule->createMaxMinPieChartData();
                _pieChart = new csrc::SFPieChart(_monitorModule->_pieChartData, \
sf::Vector2f(_position.x + _size.x * 0.95 - (_size.x < _size.y ? _size.x / 6 : _size.y / 6) - \
(std::to_string((int) _monitorModule->_displays->GetMax()).length() + _monitorModule->_displays->MaxString.length() \
> std::to_string((int) _monitorModule->_displays->GetActual()).length() + _monitorModule->_displays->ActualString.length() ? \
std::to_string((int) _monitorModule->_displays->GetMax()).length() + _monitorModule->_displays->MaxString.length() + 3 : \
std::to_string((int) _monitorModule->_displays->GetActual()).length() + _monitorModule->_displays->ActualString.length() + 3) * _headlineText.getCharacterSize(), _position.y + _size.y  * 0.5), \
_size.x < _size.y ? _size.x / 3 : _size.y / 3, &_monitorModule->_resources->stdFont);
                _pieChart->GenerateVertices();
                break;
            case IMonitorModule::BARGRAPH:
                _monitorModule->createMaxMinPlotData();
                _plot = new csrc::SFPlot(\
sf::Vector2f(_innerOutline.getPosition().x + _innerOutline.getSize().x / 2.2, _innerOutline.getPosition().y),\
sf::Vector2f(_innerOutline.getSize().x / 2, _innerOutline.getSize().y), \
40.0f, &_monitorModule->_resources->stdFont, "elapsed Time", _monitorModule->_displays->Y_Name);
                _plot->AddDataSet(_monitorModule->_plotData);
                _plot->SetupAxes(0, _monitorModule->_collapsedTimeSinceCreation, 0, _monitorModule->_yMax, _monitorModule->_collapsedTimeSinceCreation / 10, _monitorModule->_yMax / 10, _monitorModule->_resources->themes[_monitorModule->_resources->cur_theme].BarColor);
                _plot->GenerateVertices();
                break;
            case IMonitorModule::LINEGRAPH:
                delete _plot;
                _monitorModule->createMaxMinPlotData();
                _plot = new csrc::SFPlot(\
sf::Vector2f(_innerOutline.getPosition().x + _innerOutline.getSize().x / 2.2, _innerOutline.getPosition().y),\
sf::Vector2f(_innerOutline.getSize().x / 2, _innerOutline.getSize().y), \
40.0f, &_monitorModule->_resources->stdFont, "elapsed Time", _monitorModule->_displays->Y_Name);
                _plot->AddDataSet(_monitorModule->_plotData);
                _plot->SetupAxes(0, _monitorModule->_collapsedTimeSinceCreation, 0, _monitorModule->_yMax, _monitorModule->_collapsedTimeSinceCreation / 10, _monitorModule->_yMax / 10, _monitorModule->_resources->themes[_monitorModule->_resources->cur_theme].BarColor);
                _plot->GenerateVertices();
                break;
            default:
                break;
            }
            _text1.setString(_monitorModule->_displays->GetString1());
            _text2.setString(_monitorModule->_displays->GetString2());
            _text3.setString(_monitorModule->_displays->GetString3());
            /*_plot->ClearVertices();
            _monitorModule->updatePlot();
            _plot->SetupAxes(0, _monitorModule->_collapsedTimeSinceCreation, \
0, _monitorModule->_displays->Max, _monitorModule->_collapsedTimeSinceCreation / 10, _monitorModule->_displays->Max / 10, _monitorModule->_resources->themes[ _monitorModule->_resources->cur_theme].BarColor);
            _plot->GenerateVertices();*/
    }
}
