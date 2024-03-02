#include "WindowsEvents.h"
#include "ConsoleWrapper.h"
#include "Logger.h"

#include <thread>

int main() {
    try
    {
        WindowsEvents events;
        ConsoleWrapper console("Hello world");
        Logger log;

        events.Subscribe(&console);
        events.Subscribe(&log);

        events.ListenEvents();
    }
    catch (const std::exception &ex)
    {
        std::cout << std::endl << "Error | " << ex.what() << std::endl;
    }
    catch(...)
    {
        std::cout << std::endl << "Unexpected error." << std::endl;
    }

    // Prevents the console window from closing immediately
    std::cin.get();

    return 0;
}
