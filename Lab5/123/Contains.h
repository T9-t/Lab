#pragma once

template <typename T>

bool Contains(const T& x, T* arr_x, const int size) {

    bool in_arr = false;

    for (int i = 0; i < size; i++) {
        if (arr_x[i] == x) {

            in_arr = true;
        }
    }
    return in_arr;
}