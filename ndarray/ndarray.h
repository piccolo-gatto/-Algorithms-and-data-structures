#ifndef _NDARRAY_H
#define _NDARRAY_H

#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

class LineListException {};

template <typename T> class NDArray {
private:
    T* array;
    int size;
    int i, j;

public:
    NDArray(int _i, int _j = 1) {
        i = _i;
        j = _j;
        if (i < 0 || j < 0) {
            throw LineListException();
        }
        size = i * j;
        array = new T[size];
    }
    NDArray(vector<T> data, int _i, int _j = 1) {
        i = _i;
        j = _j;
        size = i * j;
        if (i < 0 || j < 0) {
            throw LineListException();
        }
        array = new T[size];
        int k = 0;
        for (typename std::vector<T>::iterator it = data.begin(); it != data.end(); ++it) {
            array[k] = *it;
            k++;
        }
    }
    void fill(T value) {
        for (int i = 0; i < size; ++i) {
            array[i] = value;
        }
    }
    void fillZeros() {
        fill(0);
    }
    void fillOnes() {
        fill(1);
    }
    void fillRandoms(T min = INT_MIN, T max = INT_MAX) {
        srand(time(0));
        for (int i = 0; i < size; i++) {
            array[i] = min + rand() % max;
        }
    }

    NDArray operator=(NDArray<T> other)
    {
        NDArray<T> temp_arr(i, j);
        temp_arr.fillZeros();
        if (other.i == i && other.j == j) {
            for (int x = 0; x < size; x++)
            {
                if (other.j == j && other.i == i)
                {
                    temp_arr.array[x] = other.array[x];
                }
            }
        }
        return temp_arr;
    }
    NDArray operator +(NDArray<T> other)
    {
        NDArray<T> temp_arr(i, j);
        temp_arr.fillZeros();
        if (other.i == i && other.j == j) {
            for (int x = 0; x < size; x++)
            {
                temp_arr.array[x] = array[x] + other.array[x];
            }
        }
        return temp_arr;
    }

    NDArray operator -(NDArray<T> other)
    {
        NDArray<T> temp_arr(i, j);
        temp_arr.fillZeros();
        if (other.i == i && other.j == j) {
            for (int x = 0; x < size; x++)
            {
                temp_arr.array[x] = array[x] - other.array[x];
            }
        }
        return temp_arr;
    }

    NDArray operator *(NDArray<T> other)
    {
        NDArray<T> temp_arr(i, j);
        temp_arr.fillZeros();
        if (other.i == i && other.j == j) {
            for (int x = 0; x < size; x++)
            {
                temp_arr.array[x] = array[x] * other.array[x];
            }
        }
        return temp_arr;
    }
    NDArray operator /(NDArray<T> other)
    {
        NDArray<T> temp_arr(i, j);
        temp_arr.fillZeros();
        if (other.i == i && other.j == j) {
            for (int x = 0; x < size; x++)
            {
                temp_arr.array[x] = array[x] / other.array[x];
            }
        }
        return temp_arr;
    }

    T operator[](int index) {
        return array[index];
    }

    NDArray transpose()
    {
        NDArray new_arr(j, i);
        new_arr.fillZeros();
        for (int x = 0; x < i; ++x) {
            for (int y = 0; y < j; ++y)
                new_arr.array[y * i + x] = array[x * j + y];
        }
        return new_arr;
    }

    NDArray matmul(NDArray other)
    {
        if (j == other.i && i == other.j)
        {
            NDArray new_arr(j, j);
            new_arr.fillZeros();
            int value = 0;
            for (int x = 0; x < j; ++x)
            {
                for (int y = 0; y < j; ++y)
                {
                    value = 0;
                    for (int k = 0; k < i; ++k)
                    {
                        value += array[x * i + k] * other.array[y + k * j];
                    }

                    new_arr.array[y + x * j] = value;
                }
            }

            return new_arr;
        }
        else
        {
            throw LineListException();
        }
    }

    NDArray min(int shape)
    {
        T min = 0;
        vector<T> vec;
        switch (shape)
        {
        case 0:
        {
            for (int x = 0; x < i; x++)
            {
                min = array[0 * i + x];
                for (int y = 0; y < j; y++)
                {
                    if (array[y * i + x] < min)
                    {
                        min = array[y * i + x];
                    }
                }
                vec.push_back(min);
            }
            NDArray<T> new_arr(vec, i, 1);
            return new_arr;
            break;
        }
        case 1:
        {
            for (int x = 0; x < j; x++)
            {
                min = array[x * i + 0];
                for (int y = 0; y < i; y++)
                {
                    if (array[x * i + y] < min)
                    {
                        min = array[x * i + y];
                    }
                }
                vec.push_back(min);
            }
            NDArray<T> new_arr(vec, j, 1);
            return new_arr;
            break;
        }
        default:
            throw LineListException();
            break;
        }
    }
    NDArray max(int shape)
    {
        T max = 0;
        vector<T> vec;
        switch (shape)
        {
        case 0:
        {
            for (int x = 0; x < i; x++)
            {
                max = array[0 * i + x];
                for (int y = 0; y < j; y++)
                {
                    if (array[y * i + x] > max)
                    {
                        max = array[y * i + x];
                    }
                }
                vec.push_back(max);
            }
            NDArray<T> new_arr(vec, i, 1);
            return new_arr;
            break;
        }
        case 1:
        {
            for (int x = 0; x < j; x++)
            {
                max = array[x * i + 0];
                for (int y = 0; y < i; y++)
                {
                    if (array[x * i + y] > max)
                    {
                        max = array[x * i + y];
                    }
                }
                vec.push_back(max);
            }
            NDArray<T> new_arr(vec, j, 1);
            return new_arr;
            break;
        }
        default:
            throw LineListException();
            break;
        }
    }
    NDArray mean(int shape)
    {
        vector<T> vec;
        T value = 0;
        if (shape == 0)
        {
            for (int x = 0; x < i; x++)
            {
                value = 0;
                for (int y = 0; y < j; y++)
                {
                    value += array[y * i + x];
                }
                vec.push_back(value / T(j));
            }
            NDArray<T> new_arr(vec, i, 1);
            return new_arr;
        }
        else
        {
            if (shape == 1)
            {
                for (int x = 0; x < j; x++)
                {
                    value = 0;
                    for (int y = 0; y < i; y++)
                    {
                        value += array[x * i + y];
                    }
                    vec.push_back(value / T(i));
                }
                NDArray<T> new_arr(vec, j, 1);
                return new_arr;
            }
            else
            {
                throw LineListException();
            }
        }
    }
    void print() {
        for (int x = 0; x < j; x++)
        {
            for (int y = 0; y < i; y++)
            {
                cout << array[i * x + y] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }


};
#endif
