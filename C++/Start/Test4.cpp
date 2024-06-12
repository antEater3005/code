#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int *arr;
    int size;
    cout << "Enter the size of the integer array:";
    cin >> size;
    cout << "Creating an array of size of" << size << "..";
    arr = new int[size];
    cout << "\nDynamic allocation of memory for array is successful.";
    delete arr;
    getch();
    return 0;
}