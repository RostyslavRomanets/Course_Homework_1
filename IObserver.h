//
// Created by Rostik on 3/2/2024.
//

#ifndef HOMEWORK_1_IOBSERVER_H
#define HOMEWORK_1_IOBSERVER_H


class IObserver {
public:
    virtual void CursorEnteredWindow() = 0;
    virtual void CursorLeavedWindow() = 0;

    virtual ~IObserver() = default;
};


#endif //HOMEWORK_1_IOBSERVER_H
