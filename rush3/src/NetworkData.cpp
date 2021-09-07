//
// Created by hasan on 1/23/21.
//

#include "NetworkData.hpp"
#include "getSystemData/SystemGetter.hpp"

void NetworkData::SetUpload() {
    _upload = SystemGetter::GetUpload();
}

void NetworkData::SetDownload() {
    _download = SystemGetter::GetDownload();
}

std::string NetworkData::GetUpload() const {
    return _upload;
}

std::string NetworkData::GetDownload() const {
    return _download;
}
