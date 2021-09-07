/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** mainWindow.cpp
*/

#include "mainWindow.hpp"
#include "../../getSystemData/SystemGetter.hpp"
#include "../../RamInfos.hpp"
#include "../../SwapInfos.hpp"
#include "../../CpuMhzInfo.hpp"
#include "../../CpuPercentage.hpp"

void printCpuData();

void printTotalData(int x);

void printNetworkData(int y, int x);

void printUsedRamCurrentProcess();

void printCurrentProcesses();

void printTopTenProcesses();

void printCpuDegrees();

void setColor(int percent)
{
    if (percent < 34)
        color_set(5, 0);
    else if (percent < 67)
        color_set(4, 0);
    else
        color_set(1, 0);
}

int mainNcurses()
{
    char c = '\0';
    bool cpu = true;
    bool ram = true;
    bool swap = true;
    bool user = true;
    bool network = true;
    bool processes = true;
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    timeout(500);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(6, COLOR_WHITE, COLOR_BLUE);
    color_set(1, 0);
    color_set(2, 0);
    color_set(6, 0);
    int y;
    int x;
    while (c != 'q')
    {
        getmaxyx(stdscr, y, x);
        if (processes)
        {
            printUsedRamCurrentProcess();
            printCurrentProcesses();
            printTopTenProcesses();
        }
        if (user)
            printTopLeft();
        if (network)
            printNetworkData(y, x);
        if (cpu)
            printCpuDegrees();
        if (ram)
            printRam();
        if (swap)
            printSwap(x);
        if (cpu)
            printCpuData();
        if (cpu)
            printTotalData(x);

        mvprintw(y, x, "");
        printMainBorder(y, x);
        c = getch();
        if (c == 'p')
            processes = !processes;
        else if (c == 'u')
            user = !user;
        else if (c == 'c')
            cpu = !cpu;
        else if (c == 'r')
            ram = !ram;
        else if (c == 'n')
            network = !network;
        else if (c == 's')
            swap = !swap;
        clear();
    }
    endwin();
    return (0);
}

void printCpuDegrees()
{
    color_set(6, 0);
    mvprintw(42, 132, "CPU0 Heat:");
    color_set(2, 0);
    mvprintw(42, 165, SystemGetter::GetCpuDegrees().c_str());
    color_set(6, 0);
    mvprintw(44, 132, "CPU1 Heat:");
    color_set(2, 0);
    mvprintw(44, 165, SystemGetter::GetCpu2Degree(0).c_str());
    color_set(6, 0);
    mvprintw(46, 132, "CPU2 Heat:");
    color_set(2, 0);
    mvprintw(46, 165, SystemGetter::GetCpu2Degree(1).c_str());
    color_set(6, 0);
    mvprintw(48, 132, "CPU3 Heat:");
    color_set(2, 0);
    mvprintw(48, 165, SystemGetter::GetCpu2Degree(2).c_str());
}

void printTopTenProcesses()
{
    color_set(6, 0);
    std::string processes = SystemGetter::GetTopTenProcesses();
    mvprintw(37, 3, "Current process:");
    color_set(2, 0);
    std::string line = processes;
    size_t cur = line.find('\n');
    std::string startLine = processes.substr(0, cur);
    std::string rest = processes.substr(cur + 1);
    mvprintw(37, 30, startLine.c_str());
    for (int i = 0; i < 10; i++)
    {
        cur = rest.find('\n');
        line = rest.substr(0, cur);
        mvprintw(38 + i, 30, line.c_str());
        rest = rest.substr(cur + 1);
    }
    mvprintw(37, 75, startLine.c_str());
    for (int i = 0; i < 10; i++)
    {
        cur = rest.find('\n');
        line = rest.substr(0, cur);
        mvprintw(38 + i, 75, line.c_str());
        rest = rest.substr(cur + 1);
    }
//    mvprintw(37, 30, processes.c_str());
}

void printCurrentProcesses()
{
    color_set(6, 0);
    std::string processes = SystemGetter::GetCurrentProcesses();
    mvprintw(35, 3, "Number of current process:");
    color_set(2, 0);
    mvprintw(35, 50 - processes.length(), processes.c_str());
}

void printUsedRamCurrentProcess()
{
    color_set(6, 0);
    float usedBytes = SystemGetter::GetRamUsageCurrentProcess();
    std::string usString = std::to_string(usedBytes);
    mvprintw(33, 3, "Ram used by current process:");
    color_set(2, 0);
    mvprintw(33, 50 - usString.length(), usString.c_str());
    mvprintw(33, 45, " KB   ");

}

void printNetworkData(int y, int x)
{
    color_set(6, 0);
    for (int i = 0; i < y - 32; i++)
    {
        mvprintw(30 + i, 130, " ");
        mvprintw(30 + i, 129, " ");
    }
    for (int i = 130; i < x - 2; i++)
    {
        mvprintw(39, i, " ");
    }
    std::string upload = SystemGetter::GetUpload();
    std::string download = SystemGetter::GetDownload();
    mvprintw(33, 132, "Upload:");
    mvprintw(36, 132, "Download:");
    color_set(2, 0);
    mvprintw(33, x - 20 - upload.length(), upload.c_str());
    mvprintw(36, x - 20 - download.length(), download.c_str());
    mvprintw(33, x - 18, "bytes");
    mvprintw(36, x - 18, "bytes");
}

void printTotalData(int x)
{
    float actual = SystemGetter::GetCpuUsage(-1);
    color_set(6, 0);
    mvprintw(25, 3, "%d %s Cores", SystemGetter::GetNumberOfCpus(), SystemGetter::GetCpuModel(0)
    .c_str());
    setColor((int)(actual));
    mvprintw(27, 3, "Average CPU");
    for (int i = 0; (float)i < actual * 1.5; i++)
    {
        mvprintw(27, 20 + i, " ");
    }
    color_set(3, 0);
    for (int i = (int)(actual * 1.5); i < 150; i++)
    {
        mvprintw(27, 20 + i, " ");
    }
    color_set(2, 0);
    mvprintw(27, 19, "[");
    mvprintw(27, 170, "]");
    std::string ac = std::to_string(actual);
    std::string ma = std::to_string(100);
    mvprintw(28, 70, ac.c_str());
    mvprintw(28, 76, "%%    ");

    color_set(6, 0);
    for (int i = 2; i < x - 1; i++)
        mvprintw(30, i, " ");
}

void printCpuData()
{
    int nbCpu = SystemGetter::GetNumberOfCpus();
    for (int i = 0; i < nbCpu; i++)
    {
        printCPUPercentage(i);
        printCPUMhz(i);
    }
}

void printCPUMhz(int index)
{
    CpuMhzInfo p(index);
    float actual = p.GetActual();
    float max = p.GetMax();
    setColor((int)((actual / max) * 50));
    mvprintw(15 + index * 2, 3, p.GetName().c_str());
    color_set(2, 0);
    std::string ac = std::to_string((int)actual);
    size_t plus = 6 - ac.length();
    mvprintw(15 + index * 2, 22 + plus, ac.c_str());
    mvprintw(15 + index * 2, 22 + 6, "MHz");
}

void printCPUPercentage(int index)
{
    CpuPercentageInfos p(index);
    float actual = p.GetActual();
    float max = p.GetMax();
    setColor((int)(actual));
    mvprintw(15 + index * 2, 60, p.GetName().c_str());
    for (int i = 0; (float)i < (actual / max) * 100; i++)
    {
        mvprintw(15 + index * 2, 70 + i, " ");
    }
    color_set(3, 0);
    for (int i = (int)((actual / max) * 100); (float)i < max; i++)
    {
        mvprintw(15 + index * 2, 70 + i, " ");
    }
    color_set(2, 0);
    mvprintw(15 + index * 2, 69, "[");
    mvprintw(15 + index * 2, 170, "]");
    color_set(2, 0);
    std::string ac = std::to_string(actual);
    std::string ma = std::to_string(actual);
    mvprintw(15 + index * 2 + 1, 70, ac.c_str());
    mvprintw(15 + index * 2 + 1, 76, "%%    ");
}

void printRam()
{
    RamInfos r;
    float actual = r.GetActual();
    float max = r.GetMax();
    setColor((int)((actual / max) * 100));
    mvprintw(3, 60, r.GetName().c_str());
    for (int i = 0; (float)i < (actual / max) * 100; i++)
    {
        mvprintw(3, 70 + i, " ");
    }
    color_set(3, 0);
    for (int i = (int)((actual / max) * 100); i < 100; i++)
    {
        mvprintw(3, 70 + i, " ");
    }
    color_set(2, 0);
    mvprintw(3, 69, "[");
    mvprintw(3, 170, "]");
    color_set(2, 0);
    std::string ac = std::to_string(actual);
    std::string ma = std::to_string(max);
    mvprintw(4, 70, ac.c_str());
    mvprintw(4, 75, "gb /");
    mvprintw(4, 80, ma.c_str());
    mvprintw(4, 86, "gb ");
}

void printSwap(int x)
{
    SwapInfos s;
    float actual = s.GetActual();
    float max = s.GetMax();
    setColor((int)((actual / max) * 100));
    mvprintw(7, 60, s.GetName().c_str());
    for (int i = 0; (float)i < (actual / max) * 100; i++)
    {
        mvprintw(7, 70 + i, " ");
    }
    color_set(3, 0);
    for (int i = (int)((actual / max) * 100); i < 100; i++)
    {
        mvprintw(7, 70 + i, " ");
    }
    color_set(2, 0);
    mvprintw(7, 69, "[");
    mvprintw(7, 170, "]");
    color_set(2, 0);
    std::string ac = std::to_string(actual);
    std::string ma = std::to_string(max);
    mvprintw(8, 70, ac.c_str());
    mvprintw(8, 75, "gb /");
    mvprintw(8, 80, ma.c_str());
    mvprintw(8, 86, "gb ");
    color_set(6, 0);
    for (int i = 55; i < x - 2; i++)
        mvprintw(10, i, " ");
}

void printTopLeft()
{

    color_set(6, 0);
    mvprintw(3, 3, "Date and Time:");
    mvprintw(5, 3, "User:");
    mvprintw(7, 3, "Host:");
    mvprintw(9, 3, "Operating System:");
    mvprintw(11, 3, "Kernel Version:");
    
    color_set(2, 0);
    mvprintw(3, 25, SystemGetter::GetDateTime().c_str());
    mvprintw(5, 25, SystemGetter::GetUsername().c_str());
    mvprintw(7, 25, SystemGetter::GetHostname().c_str());
    mvprintw(9, 25, SystemGetter::GetOperatingSystem().c_str());
    mvprintw(11, 25, SystemGetter::GetKernelVersion().c_str());
    color_set(6, 0);

    for (int i = 2; i < 14; i++)
    {
        mvprintw(i, 55, " ");
        mvprintw(i, 54, " ");
    }
    for (int i = 2; i < 55; i++)
        mvprintw(13, i, " ");
}

void printMainBorder(int y, int x)
{
    color_set(6, 0);
    for (int i = 1; i < x - 2; i++)
    {
        mvprintw(1, i, " ");
        mvprintw(y - 2, i, " ");
    }
    for (int i = 1; i < y - 1; i++)
    {
        mvprintw(i, 1, " ");
        mvprintw(i, x - 2, " ");
    }
}
