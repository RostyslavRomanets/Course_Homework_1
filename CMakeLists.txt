cmake_minimum_required(VERSION 3.27)
project(homework_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(homework_1 main.cpp
        WindowsEvents.cpp
        WindowsEvents.h
        IObserver.h
        ConsoleWrapper.h
        Logger.h
)
