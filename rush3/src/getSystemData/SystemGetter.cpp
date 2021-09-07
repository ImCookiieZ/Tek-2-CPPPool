/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** SystemGetter.cpp
*/

#include "SystemGetter.hpp"
#include <sys/utsname.h>
#include <sstream>
#include <cassert>
#include <sys/sysinfo.h>
#include <fstream>
#include <unistd.h>
#include <climits>
#include <cstring>

std::string SystemGetter::GetDateTime()
{
    time_t actual = time(nullptr);
    char *strTime = ctime(&actual);
    std::string ret (strTime);
    return ret;
}

std::string SystemGetter::GetOperatingSystem()
{
    utsname *tmpInformation = new utsname;
    assert(tmpInformation);
    int res = uname(tmpInformation);
    assert(res == 0);
    std::stringstream ss;
    std::string tmpCutter(tmpInformation->version);
    int first = tmpCutter.find(' ');
    int second = tmpCutter.find(' ', first + 1);
    tmpCutter = tmpCutter.substr(0, second);
    ss << tmpInformation->sysname << " "  << tmpCutter << " "<< tmpInformation->machine;
    delete  tmpInformation;
    return std::string(ss.str());
}

std::string SystemGetter::GetKernelVersion()
{
    utsname *tmpInformation = new utsname;
    assert(tmpInformation);
    int res = uname(tmpInformation);
    assert(res == 0);
    std::string ret(tmpInformation->release);
    delete tmpInformation;
    return ret;
}

Utilization SystemGetter::GetRamUtilization()
{
    struct sysinfo memInfo{};
    sysinfo(&memInfo);
    unsigned long totalVirtualMem = memInfo.totalram;
    totalVirtualMem *= memInfo.mem_unit;
    float fMax = totalVirtualMem / 1000000;
    fMax /= 1000;

    unsigned long usedMem = memInfo.totalram - memInfo.freeram;
    usedMem *= memInfo.mem_unit;
    float fUsed = usedMem / 1000000;
    fUsed /= 1000;
    return {fMax, fUsed};
}

Utilization SystemGetter::GetSwapUtilization()
{
    struct sysinfo memInfo{};
    sysinfo(&memInfo);
    unsigned long totalVirtualMem = memInfo.totalswap;
    totalVirtualMem *= memInfo.mem_unit;
    float fMax = totalVirtualMem / 1000000;
    fMax /= 1000;

    unsigned long usedMem = memInfo.totalswap - memInfo.freeswap;
    usedMem *= memInfo.mem_unit;
    float fUsed = usedMem / 1000000;
    fUsed /= 1000;
    return {fMax, fUsed};
}

float SystemGetter::GetCpuUsage(int cpuIndex)
{
    int count = GetNumberOfCpus();
    assert(cpuIndex < count && (cpuIndex >= 0 || cpuIndex == -1));
    std::ifstream file("/proc/stat", std::ios::in);
    assert(file);
    unsigned long totalUser = 0;
    unsigned long totalUserLow = 0;
    unsigned long totalSys = 0;
    unsigned long totalIdle = 0;
    std::string cpuName;
    unsigned long total = 0;
    float percent = 0;
    std::string line;
    //all cpus
    if (cpuIndex == -1)
    {
        file >> cpuName >> totalUser >> totalUserLow >> totalSys >> totalIdle;
    }
    //only one cpu at index
    else
    {
        if (!getline(file, line))
            throw std::exception();
        for (int i = 0; i <= cpuIndex; i++)
        {
            if (!getline(file, line))
                throw std::exception();
        }
        std::stringstream ss;
        ss << line;
        ss >> cpuName >> totalUser >> totalUserLow >> totalSys >> totalIdle;
    }
    total = (totalUser + totalUserLow + totalSys);
    percent = total;
    total += totalIdle;
    percent /= total;
    percent *= 100;
    return percent;
}

std::string SystemGetter::GetHostname() {
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    return hostname;
}

std::string SystemGetter::GetUsername() {
    char username[LOGIN_NAME_MAX];
    getlogin_r(username, LOGIN_NAME_MAX);
    return username;
}

int SystemGetter::GetCpuMHz(int cpuIndex)
{
    int count = GetNumberOfCpus();
    assert(cpuIndex < count && cpuIndex >= 0);
    std::fstream file("/proc/cpuinfo", std::ios::in);
    assert(file);
    std::stringstream ss;
    ss << file.rdbuf();
    std::string str(ss.str());
    size_t start = 0;
    size_t end = 0;
    for (int i = 0; i <= cpuIndex; i++)
    {
        start = str.find("cpu MHz", start);
        start = str.find(": ", start) + 2;
        end = str.find('\n', start);
    }
    return std::atoi(str.substr(start, end - start).c_str());
}

int SystemGetter::countWordInFile(const std::string& filepath, const std::string& wordSearch)
{
    std::ifstream file(filepath, std::ios::in);
    std::string word;
    int count = 0;
    while (file)
    {
        file >> word;
        if (word == wordSearch)
            count++;
    }
    return count;
}

std::string SystemGetter::GetCpuModel(int cpuIndex)
{
    int count = GetNumberOfCpus();
    assert(cpuIndex < count && cpuIndex >= 0);
    std::fstream file("/proc/cpuinfo", std::ios::in);
    assert(file);
    std::stringstream ss;
    ss << file.rdbuf();
    std::string str(ss.str());
    size_t start = 0;
    size_t end = 0;
    for (int i = 0; i <= cpuIndex; i++)
    {
        start = str.find("model name", start);
        start = str.find(": ", start) + 2;
        end = str.find('\n', start);
    }
    return str.substr(start, end - start);
}

int SystemGetter::GetNumberOfCpus()
{
    int count = countWordInFile("/proc/cpuinfo", "processor");
    return count;
}

std::string SystemGetter::GetDownload()
{
    static long lastDown = 0;
    static int often = -1;
    std::fstream file("/proc/net/dev", std::ios::in);
    assert(file);
    std::string str;
    std::string line;
    while (getline(file, line))
        str = line;
    std::stringstream ss;
    ss << str;
    ss >> str >> str;
    often++;
    long tmp = std::stol(str);
    std::string ret = std::to_string(tmp - lastDown);
    if (often == 5 || often == 0)
    {
        lastDown = tmp;
        often = 1;
    }
    return ret;
}
std::string SystemGetter::GetUpload()
{
    static long lastDown = 0;
    static int often = -1;
    std::fstream file("/proc/net/dev", std::ios::in);
    assert(file);
    std::string str;
    std::string line;
    while (getline(file, line))
        str = line;
    std::stringstream ss;
    ss << str;
    ss >> str >> str>> str>> str>> str>> str>> str>> str>> str>> str;
    often++;
    long tmp = std::stol(str);
    std::string ret = std::to_string(tmp - lastDown);
    if (often == 5 || often == 0)
    {
        lastDown = tmp;
        often = 1;
    }
    return ret;
}

float SystemGetter::GetRamUsageCurrentProcess()
{
    std::ifstream file("/proc/self/status");
    int res = -1;
    std::string str;
    bool found = false;

    while (!found && getline(file, str))
    {
        if (std::strncmp(str.c_str(), "VmRSS:", 6) == 0)
            found = true;
    }if (!found)
        return 0;
    size_t start = str.find(':') + 1;
    size_t startOld = start - 1;
    str = str.substr(startOld);
    start = 1;
    startOld = 0;
    while (start - 1 == startOld)
    {
        startOld = start;
        start = str.find(' ', startOld + 1);
    }
    return std::stof(str.substr(startOld + 1, start - startOld - 1));
}

std::string SystemGetter::GetCurrentProcesses()
{
    FILE *fp = popen("ps -A --no-headers | wc -l", "r");
    if (!fp)
        return "";
    char buffer[256];
    memset(&buffer, 0, 256);
    while (fgets(&buffer[strlen(buffer)], 256 - strlen(buffer), fp));
    pclose(fp);
    return std::string (buffer);
}

std::string SystemGetter::GetTopTenProcesses()
{
    FILE *fp = popen("ps --sort=-pcpu -A | head -n 22", "r");
    if (!fp)
        return "";
    std::ostringstream stm;
    char buffer[1024];
    while (fgets(buffer, 1024, fp))
        stm << buffer;
    pclose(fp);
    return std::string (stm.str());
}

std::string SystemGetter::GetCpuDegrees()
{
    FILE *fp = popen("sensors | grep \"Core 0\"", "r");
    if (!fp)
        return "";
    std::stringstream ss;
    std::string ret;
    char buffer[1024];
    while (fgets(buffer, 1024, fp))
        ss << buffer;
    pclose(fp);
    ss >> ret >> ret >> ret;
    return ret;
}

std::string SystemGetter::GetCpu2Degree(int z)
{
    std::string const one = "sensors | grep \"temp1\" | head -n 1";
    std::string const two = "sensors | grep \"temp1\" | tail -n 2 | head -n 1";
    std::string const three = "sensors | grep \"temp1\" | head -n 1";
    std::string tstring;
    if (z == 0)
        tstring = one;
    else if (z == 1)
        tstring = two;
    else if (z == 2)
        tstring = three;
    FILE *fp = popen(tstring.c_str(), "r");
    if (!fp)
        return "";
    std::stringstream ss;
    std::string ret;
    char buffer[1024];
    while (fgets(buffer, 1024, fp))
        ss << buffer;
    pclose(fp);
    ss >> ret >> ret;
    return ret;
}
