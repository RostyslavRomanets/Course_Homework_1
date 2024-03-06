//
// Created by Rostik on 3/2/2024.
//

#ifndef HOMEWORK_1_CONSOLEWRAPPER_H
#define HOMEWORK_1_CONSOLEWRAPPER_H

#include <iostream>
#include <string>
#include <windows.h>

#include "IObserver.h"

class ConsoleWrapper: public IObserver {
    HANDLE m_console;
    std::string m_text;

    const int kDefaultColor = 7;
    const int kHighlightColor = 1;

public:
    ConsoleWrapper(std::string defaultText) : m_console(GetStdHandle(STD_OUTPUT_HANDLE)), m_text(std::move(defaultText)) {
        UpdateText();
    }

    void CursorEnteredWindow() override {
        if (!SetConsoleTextAttribute(m_console, kHighlightColor))
            throw std::runtime_error("Can not change text color");

        UpdateText();
    }

    void CursorLeavedWindow() override {
        if (!SetConsoleTextAttribute(m_console, kDefaultColor))
            throw std::runtime_error("Can not change text color");

        UpdateText();
    }

private:
    void UpdateText() {
        if (!SetConsoleCursorPosition(m_console, {0, 0}))
            throw std::runtime_error("Can not change cursor position");

        std::cout << m_text;
    }
};


#endif //HOMEWORK_1_CONSOLEWRAPPER_H
