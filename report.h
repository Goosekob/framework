#pragma once
#include <fstream>
#include <array>

namespace report {
    class Report {
    public:
        Report() {}

    void generate()
    {
        std::ofstream rep;
        rep.open ("report.html");
        rep << "<!DOCTYPE html><html><head></head><body>";
        std::array<int, 10> reportData;
        for (int i=0; i < 10; i++) {
            reportData[i] = i*5;
            rep << "<p><span style='font-weight: bold'>" << i << " </span><span>" << reportData[i] << "</span></p>";
        }
        rep << "</body></html>";
        rep.close();
    }
};
}