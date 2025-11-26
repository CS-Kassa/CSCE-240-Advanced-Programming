#include <iostream>
#include "myString.h"
using namespace std;

// Default Constructor
// Sets size to 0 and initializes pointer

myString::myString() {
    size = 0;
    data = nullptr;
}

/***********************************8*
Alternate Constructor
Inputs: int size, char array[]
Allocates memory and copies elements
**************************************/
myString::myString(int newSize, const char arr[]) {
    size = newSize;
    data = new char[size];

    for (int i = 0; i < size; i++)
        data[i] = arr[i];
}

/*****************************************
 insert function takes an int index and a char value to be inserted
 Inserts char at a specific index and changes size accordingly
 *****************************************/
void myString::insert(int index, char value) {
    if (index < 0 || index > size) {
        cout << "Error: index out of bounds.\n";
        return;
    }

    char* newArr = new char[size + 1];

    for (int i = 0; i < index; i++)
        newArr[i] = data[i];

    newArr[index] = value;

    for (int i = index; i < size; i++)
        newArr[i + 1] = data[i];

    delete[] data;
    data = newArr;
    size++;
}

/*****************************************
takes an integer to be used as an index
Removes char at given index and changes size accordingly
 *****************************************/
void myString::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Error: index out of bounds.\n";
        return;
    }

    char* newArr = new char[size - 1];

    for (int i = 0; i < index; i++)
        newArr[i] = data[i];

    for (int i = index; i < size - 1; i++)
        newArr[i] = data[i + 1];

    delete[] data;
    data = newArr;
    size--;
}

/*****************************************
takes an integer to be used as an index
Returns char at index
 *****************************************/
char myString::get(int index) {
    if (index < 0 || index >= size) {
        cout << "Error: index out of bounds.\n";
        return '\0';
    }
    return data[index];
}

/*****************************************
Deletes dynamic array and resets size
 *****************************************/
void myString::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

/*****************************************
takes a char value to be located
Returns the index of first occurrence
 *****************************************/
int myString::find(char value) {
    for (int i = 0; i < size; i++)
        if (data[i] == value)
            return i;

    return -1;
}

/*****************************************
takes another myString object
Checks if two strings match then returns bool
 *****************************************/
bool myString::equals(const myString& other) {
    if (size != other.size)
        return false;

    for (int i = 0; i < size; i++)
        if (data[i] != other.data[i])
            return false;

    return true;
}

/*****************************************
Outputs string to stdout
 *****************************************/
void myString::print() {
    for (int i = 0; i < size; i++)
        cout << data[i];
    cout << endl;
}

/*****************************************
Destructor
Frees allocated memory
 *****************************************/
myString::~myString() {
    delete[] data;
}
