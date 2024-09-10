// array_ops.cpp
#include <iostream>
#include <fstream>
#include "array_ops.hpp"

// Loads data from the input file into the array
int loadDataFromFile(const std::string& fileName, int arr[]) {
    std::ifstream inputFile(fileName);
    int index = 0;
    if (inputFile.is_open()) {
        while (inputFile >> arr[index] && index < MAX_SIZE) {
            index++;
        }
        inputFile.close();
    } else {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    return index; // Return the number of elements in the array
}

// Finds the index of an integer in the array
int findInteger(const int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Modifies the value at the given index and returns the old value via reference
void modifyValue(int arr[], int index, int newValue, int& oldValue) {
    oldValue = arr[index];
    arr[index] = newValue;
}

// Adds a new integer to the end of the array
void addInteger(int arr[], int& size, int newValue) {
    if (size < MAX_SIZE) {
        arr[size] = newValue; // Add the new value at the current size (end of the array)
        size++; // Increment the size to reflect the addition
        std::cout << "New number " << newValue << " added to the array. New size = " << size << std::endl;
    } else {
        std::cerr << "Array is full, cannot add new integer." << std::endl;
    }
}

// Replaces the value at an index with 0 or removes it from the array
void replaceOrRemove(int arr[], int& size, int index, bool remove) {
    if (index >= 0 && index < size) {
        if (remove) {
            // Shift elements left to remove the integer
            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--; // Decrease the size of the array after removing the element
        } else {
            arr[index] = 0; // Replace the value with 0
        }
    } else {
        std::cerr << "Invalid index!" << std::endl;
    }
}
