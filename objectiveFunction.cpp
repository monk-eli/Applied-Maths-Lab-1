#include "methods.h"
#include <cmath>

double objectiveFunction(double x) {
    return std::exp(std::sin(x) * std::log(x));
}