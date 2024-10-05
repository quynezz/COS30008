#include "Polynomial.h"
#include <algorithm>

using namespace std;

Polynomial::Polynomial() : fDegree(0) {
    fill(begin(fCoeffs), end(fCoeffs), 0.0);
}

bool Polynomial::operator==(const Polynomial& aRHS) const {
    if (fDegree != aRHS.fDegree) {
        return false;
    }

    for (size_t i = 0; i <= fDegree; i++) {
        if (fCoeffs[i] != aRHS.fCoeffs[i]) {
            return false;
        }
    }

    return true;
}

Polynomial Polynomial::operator*(const Polynomial& aRight) const {
    Polynomial result;
    result.fDegree = fDegree + aRight.fDegree;

    for (size_t i = 0; i <= fDegree; i++) {
        for (size_t j = 0; j <= aRight.fDegree; j++) {
            result.fCoeffs[i + j] += fCoeffs[i] * aRight.fCoeffs[j];
        }
    }

    return result;
}

ostream& operator<<(ostream& aOStream, const Polynomial& aObject) {
    bool mustPrintPlus = false;

    for (int i = static_cast<int>(aObject.fDegree); i >= 0; i--) {
        if (aObject.fCoeffs[i] != 0.0) {
            if (mustPrintPlus) {
                aOStream << " + ";
            }
            else {
                mustPrintPlus = true;
            }

            aOStream << aObject.fCoeffs[i] << "x^" << i;
        }
    }

    return aOStream;
}

istream& operator>>(istream& aIStream, Polynomial& aObject) {
    size_t lDegree;
    aIStream >> lDegree;

    aObject.fDegree = (lDegree <= MAX_POLYNOMIAL) ? lDegree : MAX_POLYNOMIAL;

    for (int i = static_cast<int>(aObject.fDegree); i >= 0; i--) {
        aIStream >> aObject.fCoeffs[i];
    }

    return aIStream;
}
