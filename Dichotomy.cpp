#include "constants.h"
#include "methods.h"
#include <fstream>

int ITERATION_COUNT_D = 0;
int FUNCTION_CALLS_D = 0;

void Dichotomy() {
    double mid;
    double a = A0;
    double b = B0;
    while (b - a > EPS) {
        ITERATION_COUNT_D++;
        mid = (b + a) / 2;

        double y1 = objectiveFunction(mid - D);
        double y2 = objectiveFunction(mid + D);

        FUNCTION_CALLS_D += 2;

        if (y1 <= y2) {
            b = mid + D;
        } else if (y1 > y2) {
            a = mid - D;
        }
    }

    std::ofstream fout (PATH);
    fout << "Dichotomy Result: " << (a+b)/2 << '\n';
    fout << "Iterations: " << ITERATION_COUNT_D << " Function calls: " << FUNCTION_CALLS_D << '\n';
    fout.close();
    }