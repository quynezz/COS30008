#include "IntVector.h"
#include <stdexcept>

IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
    : fNumberOfElements(aNumberOfElements), fElements(new int[aNumberOfElements])
{
    std::copy(aArrayOfIntegers, aArrayOfIntegers + aNumberOfElements, fElements);
}

IntVector::~IntVector() {
    delete[] fElements;
}

size_t IntVector::size() const {
    return fNumberOfElements;
}

const int IntVector::get(size_t aIndex) const {
    return (*this)[aIndex];
}

void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex) {
    if (aSourceIndex >= fNumberOfElements || aTargetIndex >= fNumberOfElements) {
        throw std::out_of_range("Illegal vector indices");
    }
    std::swap(fElements[aSourceIndex], fElements[aTargetIndex]);
}

const int IntVector::operator[](size_t aIndex) const {
    if (aIndex >= fNumberOfElements) {
        throw std::out_of_range("Illegal vector index");
    }
    return fElements[aIndex];
}
