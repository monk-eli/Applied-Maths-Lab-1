#include "constants.h"
#include "objectiveFunction.h"
#include "Dichotomy.h"

int ITERATION_COUNT = 0;
int FUNCTION_CALLS = 0;

void Dichotomy() {
    double mid;
    double a = A0;
    double b = B0;
    while (b - a > EPS) {
        ITERATION_COUNT++;
        mid = (b + a) / 2;

        double y1 = function(mid - D);
        double y2 = function(mid + D);
        FUNCTION_CALLS += 2;

        if (y1 < y2) {
            b = mid + D;
        } else if (y1 > y2) {
            a = mid - D;
        } else {
            a = mid - D;
            b = mid + D;
        }
    }

    std::ofstream fout (PATH);
    fout << "Result: " << (a+b)/2 << '\n';
    fout << "Iterations: " << ITERATION_COUNT << " Function calls: " << FUNCTION_CALLS << '\n';
    fout.close();
    }