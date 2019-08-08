#include <iostream>
#include "Array.h"

int main()
{
    Array arr(16);
    Array arr1(arr);
    Array& arrRef = arr;

    std::cout << "Sizeof(Array) is " << sizeof(Array) << '\n'
              << "Sizeof(int) is " << sizeof(int) << '\n'
              << "Sizeof(int *) is " << sizeof(int*) << '\n'
              << "Sizeof(Array&) is " << sizeof(Array&) << '\n';

    for (int i = 0; i < arr.getSize(); i++) {
        arr[i] = i*10;
    }

    arrRef[0] = 1230;

    for (int i = 0; i < arr1.getSize(); i++) {
        arr1[i] = (i+1)*100;
    }

    std::cout << arr << '\n'
              << arr1 << '\n';

    Array arr2(32);
    Array arr3(32);

    arr3 = arr2 = arr1;

    arr1 = arr1;

    std::cout << arr2 << '\n'
              << arr1 << '\n'
              << "arr3 == arr1 is " << (arr3 == arr1) << '\n'
              << "arr1 != arr is " << (arr1 != arr) << '\n';
}