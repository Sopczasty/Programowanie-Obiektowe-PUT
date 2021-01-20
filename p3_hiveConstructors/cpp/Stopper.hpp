#pragma once

#include <iostream>
#include <string>
#include <chrono>

class Stopper {
private:
    std::chrono::high_resolution_clock::time_point *startTime;
    std::chrono::high_resolution_clock::time_point *endTime;

public:
    void start() const;
    void stop() const;
    void reset() const;
    void measure() const;
    ~Stopper();
    Stopper();
};