#include <iostream>
using namespace std;

int dp[101][100001];
int w[101], v[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, K;
    cin >> n >> K;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }

    // dp[i][j]: 1~i번 물건까지 고려했을 때, 무게 한계 j로 얻을 수 있는 최대 가치
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (j < w[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(
                        dp[i-1][j],
                        dp[i-1][j - w[i]] + v[i]
                );
            }
        }
    }

    cout << dp[n][K] << "\n";
    return 0;
}