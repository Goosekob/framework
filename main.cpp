#include "time.h"
#include "report.h"
#include "threading.h"
#include "io.h"
#include <iostream>


void f1() {
    std::cout << "F1" << std::endl;
}
void f2(int x) {
    std::cout << "F2 " << x+10 << std::endl;
}
void f3() {
    std::cout << "F3" << std::endl;
}
int f4() {
    std::cout << "F4" << std::endl;
    return 5;
}
void f5() {
    std::cout << "F5" << std::endl;
}

int main(){
    {
        timecontrol::TimeControl tc;
        int x = 5;
        std::cout << x*x -x << std::endl;

        report::Report R;
        R.generate();
    }
    {
        int y = 10;
        thread::Thread t1(f1);
        thread::Thread t2(f2, y);
        thread::Thread t3(f3);
        thread::Thread t4(f4);
        thread::Thread t5(f5);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
    }
    {
        std::cout << "1" << std::endl;
        IO io;
        std::cout << "2" << std::endl;
        io.back();
        std::cout << "3" << std::endl;
        std::cout << io.getout() << std::endl;
    }
    return 0;
}