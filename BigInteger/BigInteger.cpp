/*  калькулятор : http://itpride.net/useful/ochen-prodvinutyj-onlajn-kalkulyator.html
 * перевод сс: http://calculatori.ru/perevod-chisel.html
 * ASCII TABLE C++: http://en.cppreference.com/w/cpp/language/ascii*/

/*Определить оперции для шаблонов
 * Вынести деление на короткое в отдельную функцию
 * Написать какие-то модули проверочные
 * мне жопа
 * */

#include <limits>
#include <iostream>
#include <cmath>
#include <vector>

template<typename T, size_t NewBase = std::numeric_limits<T>::max()>
class BigInteger {
public:
    explicit BigInteger<T, NewBase>(long long value = 0);

    explicit operator BigInteger<T, NewBase>();

    BigInteger<T, NewBase>(const BigInteger<T, NewBase> &);

    BigInteger<T, NewBase>(BigInteger<T, NewBase> &&);

    BigInteger<T, NewBase> &operator+=(const BigInteger<T, NewBase> &);

    BigInteger<T, NewBase> operator+(const BigInteger<T, NewBase> &) const;

    BigInteger<T, NewBase> &operator-=(const BigInteger<T, NewBase> &);

    BigInteger<T, NewBase> operator-(const BigInteger<T, NewBase> &) const;

    BigInteger<T, NewBase> &operator*=(const BigInteger<T, NewBase> &);

    BigInteger<T, NewBase> operator*(const BigInteger<T, NewBase> &) const;

    int operator/=(const int &);

    bool isLess(const BigInteger<T, NewBase> &);

    size_t Size();

    T operator[](size_t id);

private:
    std::vector<int> intNumber;
    std::vector<T> number;
    bool isPos = true;

    int amountOfDigits;
    int bitsForBase;

    const int POWER = std::numeric_limits<int>::digits10;
    const int BASE = (int) pow(10, std::numeric_limits<int>::digits10);

    template<typename U, size_t Base>
    friend std::istream &operator>>(std::istream &, BigInteger<U, Base> &);

    template<typename U, size_t Base>
    friend std::ostream &operator<<(std::ostream &, const BigInteger<U, Base> &);
};

template<typename T, size_t NewBase>
BigInteger<T, NewBase>::operator BigInteger<T, NewBase>() {


};

template<typename T, size_t NewBase>
BigInteger<T, NewBase>::BigInteger(long long value) {
    isPos = (value >= 0);

    value = llabs(value);

    while (value > 0) {
        intNumber.push_back(value % BASE);
        value /= BASE;
    }
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase>::BigInteger(const BigInteger<T, NewBase> &other) {
    intNumber = other.intNumber;
    isPos = other.isPos;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase>::BigInteger(BigInteger<T, NewBase> &&other) {
    intNumber = other.intNumber;
    isPos = other.isPos;
    // delete bigInt;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> &BigInteger<T, NewBase>::operator+=(const BigInteger<T, NewBase> &other) {
    if (isPos == other.isPos) {
        int f = 0;
        for (int i = 0; f || i < std::max(intNumber.size(), other.intNumber.size()); ++i) {
            if (i == intNumber.size()) {
                intNumber.push_back(0);
            }

            if (i < other.intNumber.size()) {
                intNumber[i] += f + other.intNumber[i];
            }

            f = (intNumber[i] >= BASE);

            if (f)
                intNumber[i] -= BASE;
        }
    } else {
        isPos ^= true;
        *this -= other;
        isPos ^= true;
    }

    if (intNumber.back() == 0) {
        isPos = true;
    }
    return *this;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> BigInteger<T, NewBase>::operator+(const BigInteger<T, NewBase> &other) const {
    return BigInteger<T, NewBase>(*this) += other;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> &BigInteger<T, NewBase>::operator-=(const BigInteger<T, NewBase> &other) {

    if (isPos == other.isPos) {
        int f = 0;
        int ifLess = 1;

        if (isLess(other)) {
            isPos = !other.isPos;
            ifLess = -1;
            int diff = (int) other.intNumber.size() - (int) intNumber.size();
            for (int i = 0; i < diff; ++i) {
                intNumber.push_back(0);
            }
        }

        for (int i = 0; f || i < other.intNumber.size(); ++i) {
            intNumber[i] *= ifLess;
            intNumber[i] -= f;

            if (other.intNumber.size() > i)
                intNumber[i] -= (other.intNumber[i] * ifLess);

            f = (intNumber[i] < 0);

            if (f)
                intNumber[i] += BASE;
        }

        while (intNumber.size() > 1 && intNumber.back() == 0) {
            intNumber.pop_back();
        }
    } else {
        isPos ^= true;
        *this += other;
        isPos ^= true;
    }

    if (intNumber.back() == 0) {
        isPos = true;
    }
    return *this;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> BigInteger<T, NewBase>::operator-(const BigInteger<T, NewBase> &other) const {
    return BigInteger<T, NewBase>(*this) -= other;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> &BigInteger<T, NewBase>::operator*=(const BigInteger<T, NewBase> &other) {
    std::vector<int> product(intNumber.size() + other.intNumber.size());

    for (int i = 0; i < intNumber.size(); ++i) {
        int carry = 0;
        for (int j = 0; j < other.intNumber.size() || carry; ++j) {
            long long cur =
                    product[i + j] +
                    (long long) intNumber[i] * (long long) (j < other.intNumber.size() ? other.intNumber[j] : 0) +
                    carry;
            product[i + j] = cur % BASE;
            carry = int(cur / BASE);
        }
    }

//хочу как в джаве ссылку поменять
    while (product.size() > 1 && !product.back()) product.pop_back();

    intNumber = product;
    isPos = (isPos == other.isPos);
    return *this;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> BigInteger<T, NewBase>::operator*(const BigInteger<T, NewBase> &other) const {
    return BigInteger<T, NewBase>(*this) *= other;
}

template<typename T, size_t NewBase>
bool BigInteger<T, NewBase>::isLess(const BigInteger<T, NewBase> &other) {
    if (intNumber.size() == other.intNumber.size()) {
        for (int i = 0; i < intNumber.size(); ++i) {
            if (other.intNumber[i] > intNumber[i]) {
                return true;
            }
        }
    } else return other.intNumber.size() > intNumber.size();
}

template<typename T, size_t NewBase>
std::istream &operator>>(std::istream &in, BigInteger<T, NewBase> &bigInt) {
    std::string bigNumber;
    in >> bigNumber;
    std::vector<int> remainders;

    int until = 0;
    if (bigNumber[0] == '-') {
        bigInt.isPos = false;
        until = 1;
    }

    for (int i = (int) bigNumber.length() - 1; i >= until;) {
        int p = 0;
        bigInt.intNumber.push_back(0);
        while (p < bigInt.POWER && i >= until) {
            int k = bigNumber[i] - '0';
            bigInt.intNumber.back() += k * pow(10, p++);
            --i;
        }
    }

    if (!(std::numeric_limits<T>::is_integer && NewBase == 10)) {
        std::vector<int>;


        while (bigInt.intNumber.back() != 0) {
            remainders.push_back(this /= NewBase);
        }

        bigInt.bitsForBase = 1;
        while ((1 << bigInt.bitsForBase) < NewBase) {
            ++bigInt.bitsForBase;
        }

        bigInt.amountOfDigits = std::numeric_limits<T>::digits / bigInt.bitsForBase;
        bigInt.number.assign(ceil(remainders.size() / (double) bigInt.amountOfDigits), 0);

        int j = 0;
        for (int i = (int) remainders.size() - 1; i >= 0;) {
            int bitsCnt = 0;
            while (bitsCnt < bigInt.amountOfDigits) {
                int tmp = (remainders[i] << (bigInt.amountOfDigits - 1 - bitsCnt) * bigInt.bitsForBase);
                bigInt.number[j] |= tmp;
                ++bitsCnt;
                --i;
            }
            ++j;
        }
    }
}

template<typename T, size_t NewBase>
int BigInteger<T, NewBase>::operator/=(const int &a) {
    int carry = 0;

    for (auto i = (int) (intNumber.size() - 1); i >= 0; --i) {
        long long cur = (long long) carry * (long long) BASE;
        cur += intNumber[i];
        intNumber[i] = int(cur / a);
        carry = int(cur % a);
    }

    while (intNumber.size() > 1 && intNumber.back() == 0) {
        intNumber.pop_back();
    }
    return carry;
};

template<typename T, size_t NewBase>
std::ostream &operator<<(std::ostream &out, const BigInteger<T, NewBase> &other) {
    if (!other.isPos) {
        out << '-';
    }

    out << other.intNumber.back();
    if (other.intNumber.back() != 0) {
        for (int i = (int) other.intNumber.size() - 2; i >= 0; --i) {
            long long b = other.BASE;
            long long tmp = other.intNumber[i];
            while (b > 1) {
                b /= 10;
                out << tmp / b;
                tmp %= b;
            }
        }
    }
    return out;
}

template<typename T, size_t NewBase>
T BigInteger<T, NewBase>::operator[](size_t id) {
    return number[ceil(id / (double) amountOfDigits)];
}

template<typename T, size_t NewBase>
size_t BigInteger<T, NewBase>::Size() {
    return number.size();
}
