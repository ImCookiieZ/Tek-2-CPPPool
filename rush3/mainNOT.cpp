#include <iostream>
#include "src/getSystemData/SystemGetter.hpp"
#include "src/User.hpp"
#include "src/CpuMhzInfo.hpp"
#include "src/RamInfos.hpp"
int main()
{
    std::cout << SystemGetter::GetDateTime() << std::endl;
    std::cout << SystemGetter::GetOperatingSystem() << std::endl;
    std::cout << SystemGetter::GetKernelVersion() << std::endl;
    Utilization u = SystemGetter::GetRamUtilization();
    std::cout << "Actual: " << u.Actual << " Max: " << u.Max << " --> " << u.GetPercentage()
    << "%"<< std::endl;
    Utilization sw = SystemGetter::GetSwapUtilization();
    std::cout << "swap: Actual: " << sw.Actual << " Max: " << sw.Max << " --> " << sw.GetPercentage()
              << "%"<< std::endl;
    std::cout << SystemGetter::GetCpuUsage(-1) << std::endl;
    std::cout << SystemGetter::GetCpuUsage(0) << std::endl;
    std::cout << SystemGetter::GetCpuUsage(1) << std::endl;
    std::cout << SystemGetter::GetCpuUsage(2) << std::endl;
    std::cout << SystemGetter::GetCpuUsage(3) << std::endl;
    User user;
    std::cout << user.GetUsername() << std::endl;
    std::cout << user.GetHostname() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    std::cout << SystemGetter::GetCpuMHz(0) << std::endl;
    std::cout << SystemGetter::GetCpuModel(0) << std::endl;
    RamInfos r;
    std::cout << r.GetActual() << std::endl;
    std::cout << r.GetMax() << std::endl;
    CpuMhzInfo m(2);
    std::cout << m.GetActual() << std::endl;
    std::cout << m.GetMax() << std::endl;
    std::cout << SystemGetter::GetDownload() << std::endl;
    std::cout << SystemGetter::GetUpload() << std::endl;
    std::cout << SystemGetter::GetRamUsageCurrentProcess() << std::endl;
    std::cout << SystemGetter::GetCurrentProcesses() << std::endl;
    std::string processes = SystemGetter::GetTopTenProcesses();
    std::string line = processes;
    std::string rest = processes;
    size_t cur = line.find('\n');
    std::string startLine = processes.substr(0, cur);
    printf("%s", startLine.c_str());
    for (int i = 0; i < 10; i++)
    {
        cur = rest.find('\n');
        line = rest.substr(0, cur);
        printf("%s", line.c_str());
        rest = rest.substr(cur + 1);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << SystemGetter::GetCpuDegrees() << std::endl;

    return 0;
}
