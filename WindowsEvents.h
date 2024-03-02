//
// Created by Rostik on 3/2/2024.
//

#ifndef HOMEWORK_1_WINDOWSEVENTS_H
#define HOMEWORK_1_WINDOWSEVENTS_H

#include <windows.h>
#include <list>

class IObserver;

class WindowsEvents {
    RECT m_consoleDimensions;
    POINT m_mousePos;
    bool m_isCursorInWindow = false;

    std::list<IObserver *> m_observers;

public:
    void Subscribe(IObserver *observer);
    void Unsubscribe(IObserver *observer);

    void ListenEvents();

private:
    void Notify();
    bool CheckIfCursorInWindow();
    void UpdateConsoleDimensions();
    void UpdateMousePos();
};


#endif //HOMEWORK_1_WINDOWSEVENTS_H
