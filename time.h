#pragma once
#include <chrono>
#include <iostream>

namespace timecontrol {
    class TimeControl {
        std::chrono::steady_clock::time_point startTime;
    public:
        TimeControl(){
            startTime = std::chrono::steady_clock::now();
        };

        ~TimeControl() {
            std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
            std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << '\n';
        };
    };
}