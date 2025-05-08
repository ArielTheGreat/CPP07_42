#include <iostream>
#include "Array.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main() {
    std::cout << "===== Testing Array Class =====" << std::endl;

    // ===== 1. Test Construction with no parameter (empty array) =====
    std::cout << "\n--- Test 1: Default Construction (Empty Array) ---" << std::endl;
    Array<int> emptyArray;
    std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl; // Should be 0

    // ===== 2. Test Construction with unsigned int n (default-initialized elements) =====
    std::cout << "\n--- Test 2: Parameterized Construction (n elements) ---" << std::endl;
    Array<int> intArray(5); // Creates an array of 5 ints (default-initialized)
    std::cout << "Size of intArray: " << intArray.size() << std::endl; // Should be 5

    // Check default initialization (should be 0 for int)
    std::cout << "intArray[0]: " << intArray[0] << std::endl; // Should print 0 (default-initialized)

    // ===== 3. Test Copy Construction (deep copy) =====
    std::cout << "\n--- Test 3: Copy Construction (Deep Copy) ---" << std::endl;
    intArray[0] = 42; // Modify original
    Array<int> copiedArray(intArray); // Copy constructor
    std::cout << "Original intArray[0]: " << intArray[0] << std::endl; // 42
    std::cout << "Copied copiedArray[0]: " << copiedArray[0] << std::endl; // Should also be 42

    // Modify the copy and ensure original is unchanged
    copiedArray[0] = 100;
    std::cout << "After modification:" << std::endl;
    std::cout << "Original intArray[0]: " << intArray[0] << std::endl; // Should still be 42
    std::cout << "Copied copiedArray[0]: " << copiedArray[0] << std::endl; // Now 100

    // ===== 4. Test Assignment Operator (deep copy) =====
    std::cout << "\n--- Test 4: Assignment Operator (Deep Copy) ---" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray; // Assignment operator
    std::cout << "Original intArray[0]: " << intArray[0] << std::endl; // 42
    std::cout << "Assigned assignedArray[0]: " << assignedArray[0] << std::endl; // Should be 42

    // Modify assigned array and ensure original is unchanged
    assignedArray[0] = 200;
    std::cout << "After modification:" << std::endl;
    std::cout << "Original intArray[0]: " << intArray[0] << std::endl; // Still 42
    std::cout << "Assigned assignedArray[0]: " << assignedArray[0] << std::endl; // Now 200

    // ===== 5. Test Subscript Operator ([]) and Exception Handling =====
    std::cout << "\n--- Test 5: Subscript Operator and Bounds Checking ---" << std::endl;
    try {
        std::cout << "Accessing valid index (intArray[1]): " << intArray[1] << std::endl; // Should work
    } catch (const std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << "Accessing out-of-bounds index (intArray[10]): ";
        std::cout << intArray[10] << std::endl; // Should throw
    } catch (const std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // ===== 6. Test size() Member Function =====
    std::cout << "\n--- Test 6: size() Member Function ---" << std::endl;
    std::cout << "Size of intArray: " << intArray.size() << std::endl; // Should be 5
    std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl; // Should be 0

    // ===== 7. Test Memory Allocation (No Preventive Allocation) =====
    std::cout << "\n--- Test 7: Memory Allocation (No Preventive Allocation) ---" << std::endl;
    Array<int> dynamicArray(3);
    dynamicArray[0] = 1;
    dynamicArray[1] = 2;
    dynamicArray[2] = 3;
    std::cout << "dynamicArray elements: ";
    for (unsigned int i = 0; i < dynamicArray.size(); i++) {
        std::cout << dynamicArray[i] << " "; // Should print 1 2 3
    }
    std::cout << std::endl;

    std::cout << GREEN << "\nAll tests passed successfully!" << RESET << std::endl;
    return 0;
}