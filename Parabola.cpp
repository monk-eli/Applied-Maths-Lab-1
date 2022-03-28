#include "parabola.hpp"
#include "constants.h"
#include <iostream>
#include "methods.h"
#include <fstream>
#include <cstdint>

int ITERATION_COUNT_P = 0;
int FUNCTION_CALLS_P = 0;

void Parabola(){
    double a = A0, b = B0;
    while(b - a > EPS){
       ITERATION_COUNT_P++;
       double y1 = objectiveFunction(a);
       double c = (b + a)/2;
       double y2 = objectiveFunction(c);
       double y3 = objectiveFunction(b);
       double u = abs(c - (pow((c - a), 2) * ((y2 - y3) - pow((c - b), 2) * (y3 - y1))/ (2 * ((c - a) * (y2 - y3) - (c - b) * (y2 - y1)))));
       double f = objectiveFunction(u);
       FUNCTION_CALLS_P += 4;
        if(c < u) {
            if(y2 < f) {
                b = u;
            }
            else {
                a = c;
            }
        }
        else{
            if(y2 < f) {
                a = u;
            }
            else {
            b = c;
            }
        }
    }
    std::ofstream fout(PATH, std::fstream::app);
    fout << "Parabola Result: " << (b + a) / 2 << '\n';
    fout << "Iterations: " << ITERATION_COUNT_P << " Function calls: " << FUNCTION_CALLS_P << '\n';
    fout.close();
}


