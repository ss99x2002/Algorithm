#include <iostream>

using namespace std;

int n;
int dp[1000001];
int path[1000001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        path[i] = i-1;
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3]+1);
            if (dp[i] > dp[i/3]+1) path[i] = i/3;
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2]+1);
            if (dp[i] > dp[i/2]+1) path[i] = i/2;
        }
    }
    cout << dp[n] << "\n";

    while(true){
        cout << n << " ";
        if (n==1) {
            break;
        }
        if (dp[n] == dp[n-1]+1){
            n=n-1;
        }
        else if (n%2 ==0 && dp[n] == dp[n/2]+1){
            n=n/2;
        }
        else if (n%3 == 0 && dp[n] == dp[n/3]+1){
            n=n/3;
        }
    }
    return 0;
}