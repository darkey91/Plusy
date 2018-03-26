#include "BigInteger.hpp"
#include <cmath>
#include <iomanip>
#include <algorithm>


const int POWER = 16;
const long long BASE = 1e16;

BigInteger::BigInteger(long long value) {
    isPos = (value >= 0);

    value = llabs(value);

    while (value > 0) {
        num.push_back(value % BASE);
        value /= BASE;
    }
}

BigInteger::BigInteger(const BigInteger &other) {
    num = other.num;
    isPos = other.isPos;
}

BigInteger::BigInteger(BigInteger &&bigInt) {
    num = bigInt.num;
    isPos = bigInt.isPos;
    // delete bigInt;
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

            f = (num[i] >= BASE);

            if (f)
                num[i] -= BASE;
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

bool BigInteger::isLess(const BigInteger &other) {
    if (num.size() == other.num.size()) {
        for (int i = 0; i < num.size(); ++i) {
            if (other.num[i] > num[i]) {
                return true;
            }
        }
    } else return other.num.size() > num.size();
}

BigInteger &BigInteger::operator-=(const BigInteger &other) {

    if (isPos == other.isPos) {
        int f = 0;
        int ifLess = 1;

        if (isLess(other)) {
            isPos = other.isPos ^ true;
            ifLess = -1;
            int diff = other.num.size() - num.size();
            for (int i = 0; i < diff; ++i) {
                num.push_back(0);
            }
        }

        for (int i = 0; f || i < other.num.size(); ++i) {
            num[i] *= ifLess;
            num[i] -= f;

            if (other.num.size() > i)
                num[i] -= (other.num[i] * ifLess);

            f = (num[i] < 0);

            if (f)
                num[i] += BASE;
        }

        while (num.size() > 1 && num.back() == 0) {
            num.pop_back();
        }
    } else {
        isPos ^= true;
        *this += other;
        isPos ^= true;
    }

    if (num.back() == 0) {
        isPos = true;
    }
    return *this;
}

BigInteger BigInteger::operator-(const BigInteger &other) const {
    return BigInteger(*this) -= other;
}

std::istream &operator>>(std::istream &in, BigInteger &other) {
    std::string number;
    in >> number;

    int until = 0;
    if (number[0] == '-') {
        other.isPos = false;
        until = 1;
    }

    for (int i = number.length() - 1; i >= until;) {
        int p = 0;
        other.num.push_back(0);
        while (p < POWER && i >= until) {
            int k = number[i] - '0';
            other.num.back() += k * pow(10, p++);
            --i;
        }

    }
}

std::ostream &operator<<(std::ostream &out, const BigInteger &other) {
    if (!other.isPos) {
        out << '-';
    }
    out << other.num.back();
    if (other.num.back() != 0) {
        for (int i = other.num.size() - 2; i >= 0; i--) {
            long long b = BASE;
            long long tmp = other.num[i];
            while (b > 1) {
                b /= 10;
                out << tmp / b;
                tmp %= b;
            }
        }
    }
    return out;
}