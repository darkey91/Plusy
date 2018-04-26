#pragma once

#include <iostream>
#include <limits>
#include <vector>

template<typename T, size_t Base = std::numeric_limits<T>::max()>
class BigInteger {
public:
    template <typename T1, size_t NewBase>
            explicit operator BigInteger <T1, NewBase>();

    size_t Size();
    T operator[](size_t id) const;
private:

};