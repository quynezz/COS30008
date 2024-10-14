#pragma once
#include <stdexcept>
#include <cstddef> // for size_t

class IntVector {
private:
    int* fElements;
    size_t fNumberOfElements;

public:
    // Constructor: copy argument array
    IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) {
        fNumberOfElements = aNumberOfElements;
        fElements = new int[fNumberOfElements];
        for (size_t i = 0; i < fNumberOfElements; i++) {
            fElements[i] = aArrayOfIntegers[i];
        }
    }

    // Destructor: release memory
    virtual ~IntVector() {
        delete[] fElements;
    }

    // size getter
    size_t size() const {
        return fNumberOfElements;
    }

    // element getter with range checking
    const int get(size_t aIndex) const {
        if (aIndex >= fNumberOfElements) {
            throw std::out_of_range("Index out of range");
        }
        return fElements[aIndex];
    }

    // swap two elements within the vector
    void swap(size_t aSourceIndex, size_t aTargetIndex) {
        if (aSourceIndex >= fNumberOfElements || aTargetIndex >= fNumberOfElements) {
            throw std::out_of_range("Index out of range");
        }
        int temp = fElements[aSourceIndex];
        fElements[aSourceIndex] = fElements[aTargetIndex];
        fElements[aTargetIndex] = temp;
    }

    // indexer
    const int operator[](size_t aIndex) const {
        return get(aIndex);
    }
};
