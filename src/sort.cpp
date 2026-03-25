#include "sort.hpp"
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
