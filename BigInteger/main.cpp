#include "BigInteger.cpp"
#include <iostream>
#include <limits>
#include <climits>

int main() {
    BigInteger<char, 8>  b;
    std::cin >> b;
    for (int i = 0; i < b.Size(); ++i ) {
        std::cout << static_cast<int> (b[i]) <<" ";
    }
/*652314512387458751211 (в 10 сс) = 106562565416375650055353 (в 8чной сс)
 * Основание 8 , значит для хранения разряда потребуется 3 бита
 * Рассмотрим два первых разряда      вот этого чила(который над словами)
 *    1 и 0  я их записываю так (я фото отправлю)
 * Получается, что в один чар влезает два разряда, вот можешь проверить , это вроде работает
 * я в ответе просто вывожу аски код чара
 */


    /* std::cin >> c;

     std::cout << "Input :\n";
     std::cout << b << "\n";
     std::cout << c << " \n";

     BigInteger<int, 5> a = b + c;
     std::cout << "b + c = " << a << "\n";

     BigInteger<int, 5> d = b - c;
     std::cout << "b - c = " << d << "\n";

     std::cout << std::numeric_limits<long long>::max();

 */
    return 0;
}