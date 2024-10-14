#pragma once
#include "SortableIntVector.h"

class ShakerSortableIntVector :public SortableIntVector {
public:
    ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
        : SortableIntVector(aArrayOfIntegers, aNumberOfElements) {}

    void sort(Comparable aOrderFunction = [](int aLeft, int aRight) { return aLeft <= aRight; }) override {
        size_t n = size();
        bool swapped = true;
        size_t start = 0;
        size_t end = n - 1;

        while (swapped) {
            swapped = false;

            for (size_t i = start; i < end; ++i) {
                if (!aOrderFunction((*this)[i], (*this)[i + 1])) {
                    swap(i, i + 1);
                    swapped = true;
                }
            }

            if (!swapped)
                break;

            swapped = false;
            --end;

            for (size_t i = end; i > start; --i) {
                if (!aOrderFunction((*this)[i - 1], (*this)[i])) {
                    swap(i - 1, i);
                    swapped = true;
                }
            }

            ++start;
        }
    }
};
