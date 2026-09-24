#include <iostream>
#include <ctime>
#include <cstdlib>

void fillArray(int (&arr)[10]) {
    // TODO
}

void printArray(const int (&arr)[10]) {
    for (const auto &x : arr) std::cout << x << " ";
    std::cout << "\n";
}

void swapElements(int (&arr)[10], size_t i, size_t j) {
    if (i >= 10 || j >= 10) return;
    std::swap(arr[i], arr[j]);
}

void multiplyByTwo(int (&arr)[10]) {
    for (auto &x : arr) x *= 2;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
    std::cout << "=== Task 1 ===\n";
    int staticArr[10];
    fillArray(staticArr);
    printArray(staticArr);
    
    swapElements(staticArr, 1, 8);
    printArray(staticArr);
    
    multiplyByTwo(staticArr);
    printArray(staticArr);

        // ===================== ЗАДАНИЕ 2 =====================
    std::cout << "\n=== Task 2: Dynamic Array Processing ===\n";
    int N;
    std::cout << "Enter dynamic array size N: ";
    std::cin >> N;
    int* dynArr = new int[N]{};
    std::cout << "Enter " << N << " elements:\n";
    for (int i = 0; i < N; ++i) std::cin >> dynArr[i];

    auto process = [](int*& arr, int size) {
        int splitIndex = -1;
        for (int i = 0; i < size; ++i) {
            if (arr[i] < 0) { splitIndex = i; break; }
        }
        if (splitIndex != -1 && splitIndex > 0) {
            int* newArr = new int[splitIndex]{};
            for (int i = 0; i < splitIndex; ++i) newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
            std::cout << "Negative element found at index " << splitIndex 
                      << ". New size is " << splitIndex << ".\n";
        } else {
            std::cout << "No negative elements found or first element is negative.\n";
        }
    };

    process(dynArr, N);
    std::cout << "Resulting array: ";
    for (int i = 0; i < N; ++i) {
        if (dynArr[i] == 0 && i > 0) break;
        std::cout << dynArr[i] << " ";
    }
    std::cout << "\n";
    delete[] dynArr;
    dynArr = nullptr;
    std::cout << "Pointer after deletion set to nullptr: " << dynArr << "\n";

    return 0;
}