/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** SystemGetter.hpp
*/

#ifndef RUSH3_SYSTEMGETTER_HPP
#define RUSH3_SYSTEMGETTER_HPP

#include <string>
#include <iostream>
#include <ctime>

class Utilization
{
public:
    Utilization(float max, float actual) : Actual(actual), Max(max){}
    float Max;
    float Actual;
    float GetPercentage() const
    {
        return (Actual / Max) * 100;
    }
};

class SystemGetter
{
private:
    static int countWordInFile(const std::string&, const std::string&);
public:
    static std::string GetDateTime();
    static std::string GetOperatingSystem();
    static std::string GetHostname();
    static std::string GetUsername();
    static std::string GetKernelVersion();
    static Utilization GetRamUtilization();
    static Utilization GetSwapUtilization();
    static float GetCpuUsage(int cpuIndex = -1);
    static int GetCpuMHz(int cpuIndex);
    static std::string GetCpuModel(int cpuIndex);
    static int GetNumberOfCpus();
    static std::string GetUpload();
    static std::string GetDownload();
    static float GetRamUsageCurrentProcess();
    static std::string GetCurrentProcesses();
    static std::string GetTopTenProcesses();
    static std::string GetCpuDegrees();
    static std::string GetCpu2Degree(int z);
};

#endif //RUSH3_SYSTEMGETTER_HPP
