#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i < N; i++) {
        int a = i;
        int sum = i;

        while (a != 0) {
            sum = sum + a % 10;
            a = a / 10;
        }

        if (sum == N) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << '\n';
}