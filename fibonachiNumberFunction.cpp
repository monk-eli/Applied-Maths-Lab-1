#include "methods.h"
#include <cmath>
double fibonachiNumberFunction(double n) {
    return 1 / std::sqrt(5) * (pow(((1 + std::sqrt(5)) / 2),n) - pow(((1 - std::sqrt(5)) / 2),n));
}
