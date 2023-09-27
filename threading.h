#pragma once
#include <iostream>
#include <thread>

namespace thread {
    class Thread : public std::thread {
        public:
        template<typename Function, typename... Args>
        Thread(Function f, Args... args): std::thread(f, args...) {}

        ~Thread() {
            if (joinable()) {
                join();
            }
    }
};
}




       // template<typename Function, typename... Args>
        // explicit Thread(Function&& f, Args&&... args)
        // : std::thread(std::forward<Function>(f), std::forward<Args>(args)...) {}