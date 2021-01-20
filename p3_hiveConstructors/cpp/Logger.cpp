#include "Logger.hpp"

void Logger::log(std::string text) const {
    if (this->debug) {
        char timestr[1000];
        time_t t = time(NULL);
        struct tm * p = localtime(&t);
        strftime(timestr, 1000, "[ %A, %B, %d, %Y ]", p);
        printf("%s ", timestr);
        std::cout << text << std::endl;
    }
}

Logger::Logger(bool debug) {
    this->debug = debug;
}           