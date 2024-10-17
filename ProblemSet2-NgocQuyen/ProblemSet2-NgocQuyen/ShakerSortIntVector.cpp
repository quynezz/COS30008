#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
    : SortableIntVector(aArrayOfIntegers, aNumberOfElements) {}

void ShakerSortableIntVector::sort(Comparable aOrderFunction) {
    size_t l = 0;
    size_t r = size() - 1;

    while (l < r) {
        for (size_t i = l; i < r; i++) {
            if (!aOrderFunction(get(i), get(i + 1))) {
                swap(i, i + 1);
            }
        }
        r--;
        for (size_t i = r; i > l; i--) {
            if (!aOrderFunction(get(i - 1), get(i))) {
                swap(i - 1, i);
            }
        }
        l++;
    }
}
