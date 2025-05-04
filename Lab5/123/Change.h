#pragma once
#include <iostream>
#include "Contains.h"

using namespace std;

template <typename T>

bool Change(const T& x, const T& y, T* arr, const int size) {

    bool x_in_arr = Contains<T>(x, arr, size),y_in_arr = Contains<T>(y, arr, size);

    if (x_in_arr == 0 || y_in_arr == 0) {

        cout << "Error: elements do not match in array" << endl;
        return false;
    }
    else {
        int x_i = 0, y_i = 0;

        for (int i = 0; i < size; i++) {
            if (arr[i] == x) {
                x_i = i;
            }
            if (arr[i] == y) {
                y_i = i;
            }
        }
        T cop = arr[x_i];
        arr[x_i] = arr[y_i];
        arr[y_i] = cop;

        cout << "Success: elements successfully swapped" << endl;
        return true;
    }
}