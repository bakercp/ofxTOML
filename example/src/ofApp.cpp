//
// Copyright (c) 2018 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


void ofApp::setup()
{

    std::ifstream ifs(ofToDataPath("sample.toml", true));

    if (ifs.good())
    {
        const auto data = toml::parse(ifs);

        const auto answer    = toml::get<std::int64_t>(data.at("answer"));
        const auto pi        = toml::get<double>(data.at("pi"));
        const auto numbers   = toml::get<std::vector<int>>(data.at("numbers"));
        const auto timepoint = toml::get<std::chrono::system_clock::time_point>(data.at("time"));
        const auto tab       = toml::get<toml::Table>(data.at("tab"));
        const auto key       = toml::get<std::string>(tab.at("key"));

        std::cout << "answer: " << answer << std::endl;
        std::cout << "pi: " << pi << std::endl;
        std::cout << "numbers: " << ofToString(numbers) << std::endl;
        
        std::time_t t = std::chrono::system_clock::to_time_t(timepoint);
        
        std::cout << "timepoint: " << std::ctime(&t) << std::endl;
        std::cout << "key: " << key << std::endl;
    }
    else
    {
        ofLogError() << "Unable to open sample.toml.";
    }

    ofExit();
}
