/*
#include <iostream>
using namespace std;

const int k = 16;
const int N = 1e5;
const int ZERO = 1e9 + 1; // min(ZERO, x) = min(x, ZERO) = x (for any x)

int Arr[N];

int main()
{
    int n, a1;
    cin >> n >> a1; // array size
    int table[N][k + 1]; // k + 1 because we need to access table[r][k]

    Arr[1] = a1;
    table[1][0] = a1;

    for (int i = 2; i <= n; ++i) {
        Arr[i] = (23 * Arr[i - 1] + 21563) % 16714589;

    }



    // build Sparse Table
    for(int i = 0; i < n; i++)
        table[i][0] = Arr[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 4; ++j) {
            cout << table[i][j] <<" ";
        }
         cout << endl;
    }

   */
/* cin >> q; // number of queries
    for(int i = 0; i < q; i++) {
        cin >> L >> R; // boundaries of next query, 0-indexed
        int answer = ZERO;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                answer = min(answer, table[L][j]);
                L += 1 << j; // instead of having L', we increment L directly
            }
        }
        cout << answer << endl;
    }*//*

    return 0;
}*/
