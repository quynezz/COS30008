#include "Polynomial.h"
#include <cmath>

using namespace std;

double Polynomial::operator()(double aX) const {
    double result = 0.0;

    for (size_t i = 0; i <= fDegree; i++) {
        result += fCoeffs[i] * std::pow(aX, i);
    }
    return result;
}

Polynomial Polynomial::getDerivative() const {
    Polynomial result;

    if (fDegree == 0) {
        return result; 
    }

    result.fDegree = fDegree - 1;

    for (size_t i = 1; i <= fDegree; i++) {
        result.fCoeffs[i - 1] = fCoeffs[i] * i;
    }

    return result;
}

Polynomial Polynomial::getIndefiniteIntegral() const {
    Polynomial result;

    result.fDegree = fDegree + 1;

    for (size_t i = 0; i <= fDegree; i++) {
        result.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);
    }

    return result;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const {
    return this->getIndefiniteIntegral()(aXHigh) - this->getIndefiniteIntegral()(aXLow);
}
