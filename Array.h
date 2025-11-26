/*
Programmer: Nabeyou Kassa
Date: 10/22/2025 9:00 PM

Program Description:
This program uses functions to manipulate a dynamic array of doubles.
It will insert, remove, find, compare, and print elements, while also being able to clear and initialize the array.

Input: 
User inputs array size and element values using standard input
User also inputs indices for insertion and removal of elements

Output:
It will display the arrays contents and print messages for invalid operations

Licesning Information
This code is for academic purposes and may be freely modified
*/

#ifndef ARRAY_H
#define ARRAY_H

// Inserts a number into array at chosen index
void insert(int index, double num, double *&arr, int &size);

// Removes a number from array at chosen index
void remove(int index, double *&arr, int &size);

// Returns the element at a chosen index
double get(int index, double *arr, int size);

// Clears the entire array
void clear(double *&arr, int &size);

// Returns the first index which a given number is found, -1 if not found
int find(double num, double *arr, int size);

// returns true if the contents of two arrays are the same, false otherwise
bool equals(double *arr1, int size1, double *arr2, int size2);

// Uses input to populate the array
void init(double *arr, int size);

// Prints the elements of the array
void print(double *arr, int size);

#endif // ARRAY_H

