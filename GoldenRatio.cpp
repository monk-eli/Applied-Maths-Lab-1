#include <iostream>
#include "constants.h"
#include "methods.h"
#include <fstream>

int ITERATION_COUNT_GR = 0;
int FUNCTION_CALLS_GR = 0;

void GoldenRatio() {
    double a = A0, b = B0;
    double x1 = b - (b - a) / GR;
    double x2 = a + (b - a) / GR;
    double y1 = objectiveFunction(x1);
    double y2 = objectiveFunction(x2);

    FUNCTION_CALLS_GR += 2;

    while (b - a > EPS) {
        ITERATION_COUNT_GR++;

        if (y1 <= y2) {
            b = x2;
            x2 = x1;
            y2 = y1;
            x1 = b - (b - a) / GR;
            y1 = objectiveFunction(x1);

            FUNCTION_CALLS_GR++;
        } else {
            a = x1;
            x1 = x2;
            y1 = y2;
            x2 = a + (b - a) / GR;
            y2 = objectiveFunction(x2);

            FUNCTION_CALLS_GR++;
        }
    }

    std::ofstream fout(PATH, std::fstream::app);
    fout << "Golden Ratio Result: " << (a + b) / 2 << '\n';
    fout << "Iterations: " << ITERATION_COUNT_GR << " Function calls: " << FUNCTION_CALLS_GR << '\n';
    fout.close();
}

