#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

void bubbleSort(int* arr, size_t size) {
    if (arr == nullptr) {
        throw invalid_argument("Array pointer is null");
    }
    
    for (size_t i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int* readArray(size_t& size) {
    cout << "Enter array size: ";
    while (!(cin >> size) || size <= 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Invalid size. Enter a positive integer: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    int* arr = new int[size];
    cout << "Enter " << size << " integers: ";
    for (size_t i = 0; i < size; ++i) {
        while (!(cin >> arr[i])) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Invalid value. Enter integer #" << (i + 1) << ": ";
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return arr;
}

void printArray(const int* arr, size_t size) {
    cout << "[";
    for (size_t i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    try {
        size_t size;
        int* arr = readArray(size);
        
        cout << "Original array: ";
        printArray(arr, size);
        
        bubbleSort(arr, size);
        
        cout << "Sorted array: ";
        printArray(arr, size);
        
        delete[] arr;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
