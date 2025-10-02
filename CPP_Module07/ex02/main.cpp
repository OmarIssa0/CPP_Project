#include "Array.hpp"
#include <iostream>

int main() {
    try {
        Array<int> arr(5);

        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i * 10;
        }

        for (unsigned int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        Array<int> arr2 = arr;
        arr2[0] = 999;

        std::cout << "arr2[0] = " << arr2[0] << std::endl;
        std::cout << "arr[0] = " << arr[0] << std::endl;

        std::cout << arr[10] << std::endl; 
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
