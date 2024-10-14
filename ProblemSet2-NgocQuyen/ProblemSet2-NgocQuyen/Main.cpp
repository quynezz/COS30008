#include <iostream>
#include <stdexcept>
using namespace std;

// Uncomment to enable each problem test case
//#define P1
//#define P2
#define P3

#ifdef P1
#include "IntVector.h"
void runP1() {
    int lArray[] = { 34, 65, 890, 86, 16, 218, 20, 49, 2, 29 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);
    IntVector lVector(lArray, lArrayLength);
    cout << "Test range check:" << endl;
    try {
        int lValue = lVector[lArrayLength];
        cerr << "Error, you should not see " << lValue << " here!" << endl;
    }
    catch (out_of_range& e) {
        cerr << "Properly caught error: " << e.what() << endl;
    }

    cout << "Test swap:" << endl;
    try {
        cout << "lVector[3] = " << lVector[3] << endl;
        cout << "lVector[6] = " << lVector[6] << endl;
        lVector.swap(3, 6);
        cout << "lVector.get(3) = " << lVector.get(3) << endl;
        cout << "lVector.get(6) = " << lVector.get(6) << endl;
    }
    catch (out_of_range& e) {
        cerr << "Properly caught error: " << e.what() << endl;
    }
}
#endif

#ifdef P2
#include "SortableIntVector.h"
void runP2() {
    int lArray[] = { 34, 65, 890, 86, 16, 218, 20, 49, 2, 29 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);
    SortableIntVector lVector(lArray, lArrayLength);
    cout << "Bubble Sort:" << endl;
    cout << "Before sorting:" << endl;
    for (size_t i = 0; i < lVector.size(); i++) {
        cout << lVector[i] << " ";
    }
    cout << endl;

    lVector.sort([](int aLeft, int aRight) { return aLeft <= aRight; }); // Sort in ascending order

    cout << "After sorting:" << endl;
    for (size_t i = 0; i < lVector.size(); i++) {
        cout << lVector[i] << ' ';
    }
    cout << endl;
}
#endif

#ifdef P3
#include "ShakerSortableIntVector.h"
void runP3() {
    int lArray[] = { 34, 65, 890, 86, 16, 218, 20, 49, 2, 29 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);
    ShakerSortableIntVector lVector(lArray, lArrayLength);
    cout << "Cocktail Shaker Sort:" << endl;
    cout << "Before sorting:" << endl;
    for (size_t i = 0; i < lVector.size(); i++) {
        cout << lVector[i] << ' ';
    }
    cout << endl;

    lVector.sort([](int aLeft, int aRight) { return aLeft >= aRight; }); // Sort in descending order

    cout << "After sorting:" << endl;
    for (size_t i = 0; i < lVector.size(); i++) {
        cout << lVector[i] << ' ';
    }
    cout << endl;
}
#endif

int main() {
#ifdef P1
    runP1();
#endif
#ifdef P2
    runP2();
#endif
#ifdef P3
    runP3();
#endif
    return 0;
}
