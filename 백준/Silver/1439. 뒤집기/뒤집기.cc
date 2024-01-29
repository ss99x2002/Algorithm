#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;

    int zero = 0;
    int one = 0;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != S[i + 1]) {
            if (S[i] == '0') {
                zero = zero + 1;
            }
            else if (S[i] == '1') {
                one = one + 1;
            }
        }
    }
    cout << min(zero, one);
}
