#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

long long  n;
long long T[1500001];
long long P[1500001];
long long dp[1500001];

int main() {
    cin >> n;

    // dp[i] = i일부터 퇴사 전까지 벌 수 있는 최대 이익.
    for (int i=1; i<=n; i++){
        cin >> T[i] >> P[i];
    }

    for (int i=n; i>0; i--){
        if (i+T[i] > n+1){
            dp[i] = dp[i+1];
        }
        else {
            dp[i] = max(dp[i+1], dp[i+T[i]] + P[i]);
        }
    }
    cout << dp[1] << "\n";
}

