#include <iostream>

using namespace std;

long long n, t;
long long dp[1000001];

long long dpCal(long long n) {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%1000000009;
    }
    return dp[n];
}

void dpClear(long long n){
    for (long long i=0; i<=n; i++){
        dp[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (long long i = 0; i < t; i++) {
        cin >> n;
        cout << dpCal(n) << "\n";
        dpClear(n);
    }
}