#include "objectiveFunction.h"
#include <cmath>

double function(double x) {
    return std::exp(std::sin(x) * std::log(x));
}