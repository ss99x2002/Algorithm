#include <iostream>

using namespace std;

// 앞에 있는 상자의 크기가, 뒤에있는 상자의 크기보다 작으면
// 앞에 있는 상자를 뒤에있는 상자 안에 넣을 수 있다.

// 상자의 크기가 주어질 때, 한번에 넣을 수 있는 최대 상자 개수?

int n;
int boxs[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> boxs[i];
        dp[i] = 1;
    }

    for (int i=2; i<=n; i++){
        for (int j=1; j<i; j++){ //1부터 자기자신까지 봄.
            // 거기서 자기보다 작으면, 작은값에 +1
            if (boxs[j] < boxs[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

}