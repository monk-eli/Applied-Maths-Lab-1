#include "fibonachi.hpp"
#include "constants.h"
#include <iostream>
#include "methods.h"
#include <fstream>

int ITERATION_COUNT_F = 0;
int FUNCTION_CALLS_F = 0;

void fibonachi()
{
    double a = A0, b = B0;
    int n = (b - a) / EPS;
    double x1 = a + (fibonachiNumberFunction(n) / fibonachiNumberFunction(n + 2)) * (b - a);
    double x2 = a + (fibonachiNumberFunction(n + 1) / fibonachiNumberFunction(n + 2)) * (b - a);
    double y1 = objectiveFunction(x1);
    double y2 = objectiveFunction(x2);
    FUNCTION_CALLS_F += 2;
    while(b - a > EPS){
        ITERATION_COUNT_F++;
        if(y1 <= y2){
            b = x2;
            x2 = x1;
            y2 = y1;
            x1 = a + (fibonachiNumberFunction(n) / fibonachiNumberFunction(n + 2)) * (b - a);
            y1 = objectiveFunction(x1);
            FUNCTION_CALLS_F++;
        }
        else {
            a = x1;
            x1 = x2;
            y1 = y2;
            x2 = a + (fibonachiNumberFunction(n + 1) / fibonachiNumberFunction(n + 2)) * (b - a);
            y2 = objectiveFunction(x2);
            FUNCTION_CALLS_F++;
        }
    }
    std::ofstream fout(PATH, std::fstream::app);
    fout << "Fibonachi Result: " << (a + b) / 2 << '\n';
    fout << "Iterations: " << ITERATION_COUNT_F << " Function calls: " << FUNCTION_CALLS_F << '\n';
    fout.close();
}

