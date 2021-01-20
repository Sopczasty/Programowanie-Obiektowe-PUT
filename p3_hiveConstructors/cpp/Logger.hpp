#pragma once

#include <iostream>
#include <chrono>
#include <time.h>
#include <string>

class Logger{
    public:
        bool debug;
        void log(std::string text) const;
        Logger(bool isTrue);
};