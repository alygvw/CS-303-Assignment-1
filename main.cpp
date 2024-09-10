// main.cpp
#include <iostream>
#include <stdexcept>
#include "array_ops.hpp"

using namespace std; // Use the std namespace for standard library functions

int main() {
    int arr[MAX_SIZE]; // Fixed-size array
    int size = 0;

    // Load data from the input file
    size = loadDataFromFile("input.txt", arr);
    if (size == -1) {
        return 1; // Exit if file could not be opened
    }

    try {
        // Ask the user for an integer to search for
        int userInput;
        cout << "\nPlease enter an integer to search for: ";
        if (!(cin >> userInput)) {
            throw invalid_argument("Invalid input: please enter an integer.");
        }

        // Check if the entered integer exists in the array
        int index = findInteger(arr, size, userInput);
        if (index != -1) {
            cout << "Value " << userInput << " found at index: " << index << endl;
        } else {
            cout << "Value " << userInput << " not found in the array." << endl;
        }

        // Ask the user for an index and a new value to modify
        int modifyIndex, newValue, oldValue;
        cout << "\nEnter the index of the number you want to modify: ";
        if (!(cin >> modifyIndex)) {
            throw invalid_argument("Invalid input: index must be an integer.");
        }

        // Check if the index is valid
        if (modifyIndex < 0 || modifyIndex >= size) {
            throw out_of_range("Invalid index: index out of bounds.");
        }

        cout << "Enter the new value: ";
        if (!(cin >> newValue)) {
            throw invalid_argument("Invalid input: value must be an integer.");
        }

        // Modify the value and get the old value
        modifyValue(arr, modifyIndex, newValue, oldValue);
        cout << "Value at index " << modifyIndex << " modified. Old value = "
             << oldValue << ", New value = " << newValue << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1; // Exit on invalid input
    } catch (const out_of_range& e) {
        cerr << e.what() << endl;
        return 1; // Exit on out-of-bounds index
    }

    try {
        // Ask the user to enter a new integer to add to the array
        int addValue;
        cout << "\nEnter a new integer to add to the array: ";
        if (!(cin >> addValue)) {
            throw invalid_argument("Invalid input: please enter a valid integer.");
        }

        // Add the new integer to the end of the array
        addInteger(arr, size, addValue);
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1; // Exit on invalid input
    }

    try {
        // Ask the user if they want to replace or remove an element at a given index
        int replaceRemoveIndex;
        char option;
        cout << "\nEnter the index of the number you want to replace or remove: ";
        if (!(cin >> replaceRemoveIndex)) {
            throw invalid_argument("Invalid input: index must be an integer.");
        }

        // Check if the index is valid
        if (replaceRemoveIndex < 0 || replaceRemoveIndex >= size) {
            throw out_of_range("Invalid index: index out of bounds.");
        }

        cout << "Enter 'r' to replace with 0 or 'R' to remove the number: ";
        cin >> option;

        if (option == 'r') {
            replaceOrRemove(arr, size, replaceRemoveIndex, false); // Replace with 0
            cout << "Value at index " << replaceRemoveIndex << " replaced with 0." << endl;
        } else if (option == 'R') {
            replaceOrRemove(arr, size, replaceRemoveIndex, true); // Remove the value
            cout << "Value at index " << replaceRemoveIndex << " removed from the array." << endl;
            cout << "New array size = " << size << endl;
        } else {
            throw invalid_argument("Invalid input: please enter 'r' or 'R'.");
        }
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1; // Exit on invalid input
    } catch (const out_of_range& e) {
        cerr << e.what() << endl;
        return 1; // Exit on out-of-bounds index
    }

    return 0;
}
