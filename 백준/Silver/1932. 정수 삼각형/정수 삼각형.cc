#include <iostream>

using namespace std;


int n;
int dp[501][501];

void calMinSum() {

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i - 1; j++) {
            int tmp = dp[i - 1][j];
            dp[i - 1][j] = tmp + max(dp[i][j], dp[i][j + 1]);
        }
    }

    cout << dp[1][1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; // 삼각형의 크기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];
        }
    }
    calMinSum();
}