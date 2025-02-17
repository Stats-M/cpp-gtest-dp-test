#pragma once

#include <vector>

template <typename T>
T get_sum(std::vector<T> args)
{
    T sum = static_cast<T>(0);
    for (T el : args)
    {
        sum += el;
    }
    return sum;
}
