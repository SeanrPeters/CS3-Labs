#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

class Logger
{
public:

    void report(const std::string& str)
    {
        Logger::fout << str << std::endl;
    }

    static Logger& instance()
    {
        static Logger theLogger;
        return theLogger;
    }

private:
    Logger();
    Logger& operator=(const Logger&) = delete;
    Logger(const Logger&) = delete;
    static void wipe();
    std::ofstream fout;
};

void Logger::wipe()
{
    Logger::instance().fout.close();
    std::cout << "done" << std::endl;
}

Logger::Logger()
{
    fout.open("log.txt", std::fstream::out | std::fstream::app);
    fout << "more lorem ipsum" << std::endl;
    atexit(wipe);
}


void theFirstFunc()

{
    Logger::instance().report("first function done");
}

void theSecondFunc()
{
    Logger::instance().report("second function done");
}

int main()
{
    theFirstFunc();
    theSecondFunc();
}


