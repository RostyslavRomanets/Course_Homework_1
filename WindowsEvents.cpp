//
// Created by Rostik on 3/2/2024.
//

#include <thread>
#include <stdexcept>

#include "WindowsEvents.h"
#include "IObserver.h"

using namespace std::chrono_literals;

void WindowsEvents::ListenEvents() {
    while (1)
    {
        if (CheckIfCursorInWindow())
        {
            if (!m_isCursorInWindow)
            {
                m_isCursorInWindow = true;
                Notify();
            }
        }
        else
        {
            if (m_isCursorInWindow)
            {
                m_isCursorInWindow = false;
                Notify();
            }
        }

        std::this_thread::sleep_for(0.1s);
    }
}

void WindowsEvents::Subscribe(IObserver *observer) {
    m_observers.push_back(observer);
}

void WindowsEvents::Unsubscribe(IObserver *observer) {
    m_observers.remove(observer);
}

void WindowsEvents::Notify() {
    for (auto observer : m_observers)
    {
        if (m_isCursorInWindow)
            observer->CursorEnteredWindow();
        else
            observer->CursorLeavedWindow();
    }
}

bool WindowsEvents::CheckIfCursorInWindow() {
    UpdateConsoleDimensions();
    UpdateMousePos();

    if (m_mousePos.x >= m_consoleDimensions.left &&
            m_mousePos.x <= m_consoleDimensions.right &&
            m_mousePos.y >= m_consoleDimensions.top &&
            m_mousePos.y <= m_consoleDimensions.bottom)
        return true;

    return false;
}

void WindowsEvents::UpdateConsoleDimensions() {
    if (!GetWindowRect(GetConsoleWindow(), &m_consoleDimensions))
        throw std::runtime_error("Can not get the console window dimensions.");
}

void WindowsEvents::UpdateMousePos() {
    if (!GetCursorPos(&m_mousePos))
        throw std::runtime_error("Can not get the cursor position.");
}
