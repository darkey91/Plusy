#pragma once

#include <iostream>
#include <cmath>
#include <vector>

class BigInteger {
public:
    explicit BigInteger(long long value = 0);

    BigInteger(const BigInteger &);

    BigInteger(BigInteger &&);

    BigInteger &operator+=(const BigInteger &);

    BigInteger operator+(const BigInteger &) const;

    BigInteger &operator-=(const BigInteger &);

    BigInteger operator-(const BigInteger &) const;

    bool isLess( const BigInteger &);

private:

    std::vector<long long> num;
    bool isPos = true;

    friend std::istream &operator>>(std::istream &, BigInteger &);
    friend std::ostream &operator<<(std::ostream &, const BigInteger &);
};

std::istream &operator>>(std::istream &, BigInteger &);

std::ostream &operator<<(std::ostream &, const BigInteger &);
