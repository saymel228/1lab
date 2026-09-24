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

    return 0;
}