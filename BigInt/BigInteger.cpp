#include <limits>
#include <iostream>
#include <cmath>
#include <vector>

template <typename T, size_t Base = std::numeric_limits<T>::max()>
class BigInteger{
public:
    explicit BigInteger<T, Base> (long long value = 0);

    //template <typename T1, size_t NewBase>
    explicit operator BigInteger<T, Base>();

    BigInteger<T, Base> (const BigInteger<T, Base> &);

    BigInteger<T, Base> (BigInteger<T, Base> &&);

    BigInteger<T, Base> &operator+=(const BigInteger<T, Base> &);

    BigInteger<T, Base>  operator+(const BigInteger<T, Base> &) const;

    BigInteger<T, Base>  &operator-=(const BigInteger<T, Base> &);

    BigInteger<T, Base>  operator-(const BigInteger<T, Base> &) const;

    bool isLess( const BigInteger<T, Base> &);

    //size_t Size();

    //T operator[](size_t id);

    std::vector<int> num;
private:

    bool isPos = true;
    const int POWER = std::numeric_limits<int>::digits10;
    const int BASE = (int)pow(10, std::numeric_limits<int>::digits10);

    template <typename  U, size_t NewBase>
    friend std::istream &operator>>(std::istream &, BigInteger<U, NewBase> &);
    template <typename U, size_t NewBase>
    friend std::ostream &operator<<(std::ostream &, const BigInteger<U, NewBase> &);
};
template <typename  T, size_t Base>
BigInteger<T, Base>::operator BigInteger<T, Base>() {

};

template<typename T, size_t NewBase>
BigInteger<T, NewBase>::BigInteger(long long value) {
    isPos = (value >= 0);

    value = llabs(value);

    while (value > 0) {
        num.push_back(value % BASE);
        value /= BASE;
    }
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase>::BigInteger(const BigInteger<T, NewBase> &other) {
    num = other.num;
    isPos = other.isPos;
}
template<typename T, size_t NewBase>
BigInteger<T, NewBase>::BigInteger(BigInteger<T, NewBase> &&bigInt) {
    num = bigInt.num;
    isPos = bigInt.isPos;
    // delete bigInt;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> &BigInteger<T, NewBase>::operator+=(const BigInteger<T, NewBase> &bigInt) {
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


template<typename T, size_t NewBase>
BigInteger<T, NewBase> BigInteger<T, NewBase>::operator+(const BigInteger<T, NewBase> &bigInt) const {
    return BigInteger<T, NewBase>(*this) += bigInt;
}

template<typename T, size_t NewBase>
bool BigInteger<T, NewBase>::isLess(const BigInteger<T, NewBase> &other) {
    if (num.size() == other.num.size()) {
        for (int i = 0; i < num.size(); ++i) {
            if (other.num[i] > num[i]) {
                return true;
            }
        }
    } else return other.num.size() > num.size();
}
template<typename T, size_t NewBase>
BigInteger<T, NewBase> &BigInteger<T, NewBase>::operator-=(const BigInteger<T, NewBase> &other) {

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

template<typename T, size_t NewBase>
BigInteger<T, NewBase> BigInteger<T, NewBase>::operator-(const BigInteger<T, NewBase> &other) const {
    return BigInteger<T, NewBase>(*this) -= other;
}

template<typename T, size_t NewBase>
std::istream &operator>>(std::istream &in, BigInteger<T, NewBase> &other) {
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
        while (p < other.POWER && i >= until) {
            int k = number[i] - '0';
            other.num.back() += k * pow(10, p++);
            --i;
        }

    }
}

template<typename T, size_t NewBase>
std::ostream &operator<<(std::ostream &out, const BigInteger<T, NewBase> &other) {
    if (!other.isPos) {
        out << '-';
    }
    out << other.num.back();
    if (other.num.back() != 0) {
        for (int i = other.num.size() - 2; i >= 0; --i) {
            long long b = other.BASE;
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
