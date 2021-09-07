//
// Created by hasan on 1/23/21.
//

#ifndef B_CPP_300_BER_3_1_CPPRUSH3_KARL_ERIK_STOERZEL_NETWORKDATA_HPP
#define B_CPP_300_BER_3_1_CPPRUSH3_KARL_ERIK_STOERZEL_NETWORKDATA_HPP

#include "Displays.hpp"
#include "getSystemData/SystemGetter.hpp"

class NetworkData : public Displays {
public:
    NetworkData() {
        SetUpload();
        SetDownload();
    }
    ~NetworkData() = default;
    void SetUpload();
    void SetDownload();
    std::string GetUpload() const;
    std::string GetDownload() const;
    std::string GetName() const override{return "Network";};
    std::string GetString1() const override
    {
        return "Download: " + SystemGetter::GetDownload() +" bytes";
    };
    std::string GetString2() const override{return "Upload: " + SystemGetter::GetUpload() +
    " bytes";};
    std::string GetString3() const override{return "";};
    float GetActual() override{return 0;};
    float GetMax() override{return 0;};

private:
    std::string _upload;
    std::string _download;
};

#endif //B_CPP_300_BER_3_1_CPPRUSH3_KARL_ERIK_STOERZEL_NETWORKDATA_HPP
