#pragma once
#include "IntVector.h"
#include <functional>

using Comparable = std::function<bool(int, int)>;

class SortableIntVector : public IntVector {
public:
    SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
        : IntVector(aArrayOfIntegers, aNumberOfElements) {}

    virtual void sort(Comparable aOrderFunction) {
        size_t n = size();
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = 0; j < n - i - 1; ++j) {
                if (!aOrderFunction((*this)[j], (*this)[j + 1])) {
                    swap(j, j + 1);
                }
            }
        }
    }
};
