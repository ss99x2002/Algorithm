#include <iostream>

using namespace std;

// 퇴사 2
// N+1번째 되는 날 퇴사하기 위해서, 남은 N일동안 최대한 많은 상담 하려고 한다.
// 상담 완료까지 걸리는 기간 Ti, 받을 수 있는 금액 Pi

// 퇴사전 백준이 얻을 수 있는 상담 최대 수익은?

int n;
int t[1500001];
int p[1500001];
int dp[1500001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    t[0] = 0;
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 1; i<=n; i++) {
        // 오늘까지 얻을 수 있는 최대 수익은, 이전 수익의 최대 수익
        // dp[i]: i일에 얻을 수 있는 최대 수익
        dp[i] = max(dp[i], dp[i-1]);
        // dp[i]는 이전 경우에 만들어졌기 때문에, 그 경우와, 선택하지 않는 경우의 max를 비교하기 위해
        // max로 이전값과 자신을 비교함.
        if (i+t[i] <= n+1){
            dp[i+t[i]] = max(dp[i+t[i]], dp[i] + p[i]);
        }
    }

    int ans = -1;
    for (int i = 1; i <= n+1; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}