#include <iostream>
#include <vector>
#include <stdexcept>
#include "sort.hpp"

using namespace std;

void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            cerr << "Usage: " << argv[0] << " num1 num2 num3 ..." << endl;
            return 1;
        }

        vector<int> arr;
        for (int i = 1; i < argc; i++) {
            arr.push_back(stoi(argv[i]));
        }

        cout << "Original array: ";
        printArray(arr);

        bubbleSort(arr.data(), arr.size());

        cout << "Sorted array: ";
        printArray(arr);

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}