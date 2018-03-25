#include "BigInteger.hpp"
#include <cmath>
#include <iomanip>
#include <algorithm>

const long long base = 1e16;
const int power = 16;

BigInteger::BigInteger(long long value) {
    isPos = (value >= 0);

    value = llabs(value);

    while (value > 0) {
        num.push_back(value % base);
        value /= base;
    }
}

BigInteger::BigInteger(const BigInteger &bigInt) {
    num = bigInt.num;
    isPos = bigInt.isPos;
}

BigInteger::BigInteger(BigInteger &&bigInt) {
    num = bigInt.num;
    isPos = bigInt.isPos;
}

BigInteger &BigInteger::operator+=(const BigInteger &bigInt) {
    if (isPos == bigInt.isPos) {
        int f = 0;
        for (int i = 0; f || i < std::max(num.size(), bigInt.num.size()); ++i) {
            if (i == num.size()) {
                num.push_back(0);
            }

            if (i < bigInt.num.size()) {
                num[i] += f + bigInt.num[i];
            }

            f = (num[i] >= base);

            if (f)
                num[i] -= base;
        }
    } else {
        isPos ^= true;
        *this -= bigInt;
        isPos ^= true;

    }

    if (num.back() == 0) {
        isPos = true;
    }
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger &bigInt) const {
    return BigInteger(*this) += bigInt;
}


BigInteger &BigInteger::operator-=(const BigInteger &bigInt) {

    if (isPos == bigInt.isPos) {
        int f = 0;
        int ifLess = 1;

        if (bigInt.num.size() > num.size() || (num.size() == bigInt.num.size() &&
                                               bigInt.num.back() > num.back())) {
            isPos = bigInt.isPos ^ 1;
            ifLess = -1;
            int diff = bigInt.num.size() - num.size();
            for (int i = 0; i < diff; ++i) {
                num.push_back(0);
            }
        }

        for (int i = 0; f || i < bigInt.num.size(); ++i) {
            num[i] *= ifLess;
            num[i] -= f;

            if (bigInt.num.size() > i)
                num[i] -= (bigInt.num[i] * ifLess);

            f = (num[i] < 0);

            if (f)
                num[i] += base;
        }

        while (num.size() > 1 && num.back() == 0) {
            num.pop_back();
        }

    } else {
        isPos ^= true;
        *this += bigInt;
        isPos ^= true;
    }

    if (num.back() == 0) {
        isPos = true;
    }
    return *this;
}

BigInteger BigInteger::operator-(const BigInteger &bigInt) const {
    return BigInteger(*this) -= bigInt;
}

std::istream &operator>>(std::istream &in, BigInteger &bigInt) {
    std::string number;
    in >> number;

    int until = 0;
    if (number[0] == '-') {
        bigInt.isPos = false;
        until = 1;
    }

    for (int i = number.length() - 1; i >= until;) {
        int p = 0;
        bigInt.num.push_back(0);
        while (p < power && i >= until) {
            int k = number[i] - '0';
            bigInt.num.back() += k * pow(10, p++);
            --i;
        }

    }
}

std::ostream &operator<<(std::ostream &out, const BigInteger &bigInt) {
    if (!bigInt.isPos) {
        out << '-';
    }
    out << bigInt.num.back();
    if (bigInt.num.back() != 0) {
        for (int i = bigInt.num.size() - 2; i >= 0; i--) {
            long long b = base;
            long long tmp = bigInt.num[i];
            while (b > 1) {
                b /= 10;
                out << tmp / b;
                tmp %= b;
            }
        }
    }
    return out;
}