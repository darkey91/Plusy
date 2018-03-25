#include "BigInteger.hpp"
#include <iostream>


int main() {

    BigInteger b, c;

    std::cin >> b;
    std::cin >> c;

    std::cout << "Input :\n";
    std::cout << b << "\n";
    std::cout << c << " \n";

    BigInteger a = b + c;
    std::cout << "b + c = " << a << "\n";

    BigInteger d = b - c;
    std::cout << "b - c = " << d << "\n";


    return 0;
}