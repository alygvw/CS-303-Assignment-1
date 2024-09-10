// array_ops.hpp
#ifndef ARRAY_OPS_HPP
#define ARRAY_OPS_HPP

const int MAX_SIZE = 150; // Maximum size of the array

// Function declarations

// Loads data from the input file into the array
int loadDataFromFile(const std::string& fileName, int arr[]);

// Finds the index of an integer in the array, returns -1 if not found
int findInteger(const int arr[], int size, int value);

// Modifies the value at the given index and returns the old value via reference
void modifyValue(int arr[], int index, int newValue, int& oldValue);

// Adds a new integer to the end of the array
void addInteger(int arr[], int& size, int newValue);

// Replaces the value at an index with 0 or removes it from the array
void replaceOrRemove(int arr[], int& size, int index, bool remove = false);

#endif
