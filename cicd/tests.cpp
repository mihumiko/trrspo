#include <iostream>
#include <cassert>
#include <stdexcept>
#include "../src/sort.hpp"

using namespace std;

void testBasicSort() {
    int arr[] = {5, 2, 8, 1, 9};
    bubbleSort(arr, 5);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 5);
    assert(arr[3] == 8);
    assert(arr[4] == 9);
    cout << "testBasicSort passed" << endl;
}

void testAlreadySorted() {
    int arr[] = {1, 2, 3, 4, 5};
    bubbleSort(arr, 5);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    assert(arr[3] == 4);
    assert(arr[4] == 5);
    cout << "testAlreadySorted passed" << endl;
}

void testReverseSorted() {
    int arr[] = {5, 4, 3, 2, 1};
    bubbleSort(arr, 5);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    assert(arr[3] == 4);
    assert(arr[4] == 5);
    cout << "testReverseSorted passed" << endl;
}

void testSingleElement() {
    int arr[] = {42};
    bubbleSort(arr, 1);
    assert(arr[0] == 42);
    cout << "testSingleElement passed" << endl;
}

void testTwoElements() {
    int arr[] = {2, 1};
    bubbleSort(arr, 2);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    cout << "testTwoElements passed" << endl;
}

void testDuplicates() {
    int arr[] = {3, 1, 3, 2, 1};
    bubbleSort(arr, 5);
    assert(arr[0] == 1);
    assert(arr[1] == 1);
    assert(arr[2] == 2);
    assert(arr[3] == 3);
    assert(arr[4] == 3);
    assert(arr[5] == 1);
    cout << "testDuplicates passed" << endl;
}

void testNullPointer() {
    try {
        bubbleSort(nullptr, 5);
        assert(false && "Should have thrown exception");
    } catch (const invalid_argument& e) {
        cout << "testNullPointer passed" << endl;
    }
}

int main() {
    cout << "Running bubble sort tests..." << endl;
    cout << "==========================" << endl;
    
    testBasicSort();
    testAlreadySorted();
    testReverseSorted();
    testSingleElement();
    testTwoElements();
    testDuplicates();
    testNullPointer();
    
    cout << "==========================" << endl;
    cout << "All tests passed" << endl;
    
    return 0;
}
