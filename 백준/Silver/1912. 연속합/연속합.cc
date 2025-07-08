#include <iostream>
using namespace std;

// 연속된 몇개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합 구하려고 한다.

int dp[100001];
int nums[100001];
int n;
int ans = -1000 * 100000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }

    dp[0] = nums[0];
    for (int i=1; i<n; i++){
        dp[i] = max(nums[i], dp[i-1]+nums[i]);
    }

    for (int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}