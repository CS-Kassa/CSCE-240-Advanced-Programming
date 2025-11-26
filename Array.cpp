#include <iostream>
#include "Array.h"
using namespace std;


/*
Insert function

Description:
Inserts number into dynamic array at chosen index and then is resized accordingly.

Inputs:
    -index: the index that the new number will be inserted at
    -num: number to insert
    -arr: reference to dynamic array pointer
    -size: reference to size of array

Outputs:
    - The array is resized and the number is inserted at the chosen index.
    - An error message is printed if the index is out of bounds.
*/

void insert(int index, double num, double *&arr, int &size){
    if (index < 0 || index > size){
        cout << "Index out of bounds." << endl;
        return;
    }

    //inserting an index so new array is size + 1
    double *nArr = new double[size + 1];
    for (int i = 0; i < index; i++){
        nArr[i] = arr[i];
    }

    nArr[index] = num;
    for (int i = index; i < size; i++){
        nArr[i + 1] = arr[i];
    }
    delete[] arr;
    arr = nArr;
    size ++;

} //end of insert


/*
Description:
Removes number from the dynamic array at the chosen index then resizes

Inputs:
    -index: index of the number to remove
    -arr: reference to dynamic array pointer
    -size: reference to size of array

Outputs:
    - The array is resized and the number at the chosen index is removed.
    - An error message is printed if the index is out of bounds.
*/

void remove(int index, double *&arr, int &size){
    if (index < 0 || index >= size){
        cout << "Index out of bounds." << endl;
        return;
    }

    //removing an index so new array is size - 1
    double *nArr = new double[size - 1];
    for (int i = 0; i < index; i++){
        nArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++){
        nArr[i - 1] = arr[i];
    }

    delete[] arr;
    arr = nArr;
    size --;

} //end of remove

/*
Function: get

Description:
Returns the element at a chosen index

Inputs:
    -index: index of the element to return
    -arr: dynamic array pointer
    -size: size of array

Outputs:
    - Returns the value stored at the chosen index
    - An error message is printed if the index is out of bounds.
*/

double get(int index, double *arr, int size){
    if (index < 0 || index >= size){
        cout << "Index out of bounds." << endl;
    }
    return arr[index];

}// end of get


/*
Function: clear

Description:
Clears the entire array

Inputs:
    -arr: reference to dynamic array pointer
    -size: reference to size of array

Outputs:
    - The array is deleted, pointer set to nullptr, and size set to 0.
*/

void clear(double *&arr, int &size){
    delete[] arr;
    arr = nullptr;
    size = 0;
}// end of clear


/*
Function: find

Description: 
Searches for the first index which a given number is found

Inputs:
    -num: number to find
    -arr: dynamic array pointer
    -size: size of array

Outputs:
    - Returns the first index which the given number is found, -1 if not found.
*/

int find(double num, double *arr, int size){
    for (int i = 0; i < size; i++){
        if (arr[i] == num){
            return i;
        }
    }
    return -1;
}// end of find


/*
Function: equals

Description:
Compares the contents of two arrays

Inputs:
    -arr1: first dynamic array pointer
    -size1: size of first array
    -arr2: second dynamic array pointer
    -size2: size of second array

Outputs:
    - returns true if the contents of two arrays are the same, false otherwise
*/

 bool equals(double *arr1, int size1, double *arr2, int size2){
    bool isEqual = true;
    if (size1 != size2){
        isEqual = false;
    }else{
        for(int i = 0; i < size1; i++){
            if (arr1[i] != arr2[i]){
                isEqual = false;
            }
        }
    }
    return isEqual;
 }// end of equals

/*
Function: init

Description:
Uses input to populate the array

Inputs:
    -arr: dynamic array pointer
    -size: size of array          

Outputs:
    - The array is populated with user input values.
*/

void init(double *arr, int size){
    cout << "Enter " << size << " numbers to populate the array." << endl;
    for (int i = 0; i < size; i++){
        cout << "Number " << i + 1 << ": ";
        cin >> arr[i];

    }   
    cout << endl;
    } // end of init

/*
Function: print

Description:
Prints the elements of the array

Inputs:
    -arr: dynamic array pointer
    -size: size of array

Outputs:
    - The elements of the array are printed to standard output.
*/
void print(double *arr, int size){
    cout << "[";
    for (int i = 0; i < size; i++){
        cout << arr[i];
        if (i < size - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
    }
 