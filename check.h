#pragma once
#include <iostream>
#include <vector>
//#include <sstream>

namespace check {
    
    class AssertionInfo {
        public:
        std::string expression;
        std::string file;
        std::size_t line;
    };

    std::vector<AssertionInfo> assertions;
    
    #define REQUIRE(expression) \
    { \
        if (!(expression)) { \
            std::ostringstream assertionStream; \
            assertionStream << "Expression \"" << #expression << "\" is false"; \
            assertions.push_back({ assertionStream.str(), __FILE__, __LINE__ }); \
            throw std::runtime_error(assertionStream.str()); \
        } \
    }

    void runAllAssertions() {
        for (const auto& assertion : assertions) {
            std::cout << "Running assertion: " << assertion.expression << " at " << assertion.file << ":" << assertion.line << std::endl;
        }
    }
}