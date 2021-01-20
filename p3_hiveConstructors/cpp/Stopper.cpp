#include "Stopper.hpp"

Stopper::Stopper() {
    this->startTime = new std::chrono::high_resolution_clock::time_point;
    this->endTime = new std::chrono::high_resolution_clock::time_point;
}

Stopper::~Stopper() {
    if(startTime != nullptr) delete startTime;
    if(endTime != nullptr) delete endTime;
}

void Stopper::start() const {
    *this->startTime = std::chrono::high_resolution_clock::now();
}

void Stopper::stop() const {
    *this->endTime = std::chrono::high_resolution_clock::now();
}

void Stopper::reset() const {
    *this->startTime = std::chrono::high_resolution_clock::now();
}

void Stopper::measure() const {
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(*endTime - *startTime).count() << " milisekund" << std::endl;
}