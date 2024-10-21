#include "KeyProvider.h"
#include <cctype>

KeyProvider::KeyProvider(const std::string& aKeyword) : fSize(aKeyword.length()), fIndex(0) {
    fKeyword = new char[fSize + 1]; 
    initialize(aKeyword);
}

KeyProvider::~KeyProvider() {
    delete[] fKeyword;
}

void KeyProvider::initialize(const std::string& aKeyword) {
    // Reallocate if necessary
    if (fSize != aKeyword.length()) {
        delete[] fKeyword;
        fSize = aKeyword.length();
        fKeyword = new char[fSize + 1]; // Allocate new memory
    }
    for (size_t i = 0; i < fSize; i++) {
        fKeyword[i] = static_cast<char>(toupper(aKeyword[i]));
    }
    fKeyword[fSize] = '\0'; 
    fIndex = 0;
}

char KeyProvider::operator*() const {
    return fKeyword[fIndex];
}

KeyProvider& KeyProvider::operator<<(char aKeyCharacter) {
    fKeyword[fIndex] = static_cast<char>(toupper(aKeyCharacter));
    if (++fIndex >= fSize) {
        fIndex = 0;
    }
    return *this;
}
