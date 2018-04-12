#include "BigInteger.cpp"
#include <iostream>
#include <limits>

int main() {


   BigInteger<int, 5> b, c;

    std::cin >> b;
    std::cin >> c;

    std::cout << "Input :\n";
    std::cout << b << "\n";
    std::cout << c << " \n";

    BigInteger<int, 5> a = b + c;
    std::cout << "b + c = " << a << "\n";

    BigInteger<int, 5> d = b - c;
    std::cout << "b - c = " << d << "\n";

    std::cout << std::numeric_limits<long long>::max();


    return 0;
}