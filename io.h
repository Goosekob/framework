#include <iostream>
#include <sstream>

class IO {
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::stringstream myout;
public:
    IO() {
        std::cout.rdbuf(myout.rdbuf());
    }
    void back() {
        std::cout.rdbuf(coutbuf);
    }

    std::string getout() {
        return myout.str();
    }
};