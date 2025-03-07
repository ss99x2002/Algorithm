#include <iostream>

using namespace std;

// 이친수 특징
// 1. 0과 1로만 이루어진 수
// 2. 1이 두번 연속 등장하지 않음 -> 즉 11을 부분 문자열로 가지지 않음
// 3. 0으로 시작하지 않음.

int n;
long long dp[91]; // 합산 값이 int 범위 넘어가는 경우 있으므로 Long long 변경해야함 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = dp[1] + dp[2];

    for (int i=4; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];
}