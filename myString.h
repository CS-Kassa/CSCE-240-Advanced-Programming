/*******************************************************\
Programmer: Nabeyou Kassa
Date/Time:  11/2/2025

Program Description:
Header file for the myString class. This class
mimics some functionalities of the
Java String class using dynamic memory allocation
with pointer arrays in C++.

Input Requirements:
Characters inserted one at a time
Index positions must be within valid bounds

Output:
Prints stored character array (string) to stdout

 Licensing:
Free for educational use.
*******************************************************/

#ifndef MYSTRING_H
#define MYSTRING_H

class myString {
private:
    char* data;   
    int size;     

public:
    // Constructors
    myString();                
    // Alternate constructor                     
    myString(int size, const char arr[]);        

    // Required methods
    void insert(int index, char value);              
    void remove(int index);                         
    char get(int index);                             
    void clear();                                    
    int find(char value);                           
    bool equals(const myString& other);              
    void print();                                    

    // Destructor to free memory
    ~myString();
};

#endif
