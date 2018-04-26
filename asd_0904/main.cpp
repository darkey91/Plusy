#include <iostream>
#include <algorithm>


using namespace std;

int main() {


    int a[50];

    for (int i = 0; i < 50; ++i) {
        a[i] = i;
    }

    for (int i = 49; i>= 0; --i) {
        int j = a[1] + rand() % a[i];
        std::cout << j << " ";
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    return 0;
}