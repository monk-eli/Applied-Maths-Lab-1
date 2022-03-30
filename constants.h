#ifndef LAB_1_CONSTANTS_H
#define LAB_1_CONSTANTS_H

#include <string>
#include <cmath>

const double EPS = 0.001;
const double D = 0.00000005; // Delta for Dichotomy method
const double A0 = 9;
const double B0 = 12;
const double GR = (1 + std::sqrt(5)) / 2; // Golden Ratio

const std::string PATH{
        "/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-1/output/lab1out.txt"}; // Insert your path to lab1out.txt
const std::string DICHOTOMYOUT{"/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-1/output/DichotomySection.txt"};
const std::string GOLDENRATIOOUT{"/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-1/output/GoldenRatioSection.txt"};
const std::string FIBONACCIOUT{"/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-1/output/FibonacciSection.txt"};
const std::string PARABOLAOUT{"/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-1/output/ParabolaSection.txt"};
const std::string BRENTOUT{"/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-1/output/BrentSection.txt"};

#endif //LAB_1_CONSTANTS_H
