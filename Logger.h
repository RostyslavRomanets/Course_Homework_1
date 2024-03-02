//
// Created by Rostik on 3/2/2024.
//

#ifndef HOMEWORK_1_LOGGER_H
#define HOMEWORK_1_LOGGER_H

#include <string>
#include <fstream>
#include <format>
#include <chrono>

#include "IObserver.h"

class Logger: public IObserver {
public:
    void CursorEnteredWindow() override {
        LogText("Enter");
    }

    void CursorLeavedWindow() override {
        LogText("Leave");
    }
private:
    void LogText(const std::string &text) {
        std::ofstream logFile("log.txt", std::ios::app);
        if (!logFile)
            throw std::runtime_error("Can not open log file.");

        auto logTime = std::format("{0:%F %T}", std::chrono::system_clock::now());
        logFile << logTime << " | " << text << "\n";
        logFile.close();
    }
};


#endif //HOMEWORK_1_LOGGER_H
