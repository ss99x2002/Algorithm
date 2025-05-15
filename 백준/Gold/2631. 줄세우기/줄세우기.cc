#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

int n;
int num;
int dp[201]; // dp[end~i]까지 연속된 수열의 원소 갯수.
int pos[201]; // num의 숫자가 줄서 있는 위치.

int main() {
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> num;
        pos[i] = num;
        dp[i] = 1;
    }

    for (int i=1; i<=n; i++){
        for (int j=i; j>=1; j--){
            if (pos[i] > pos[j]) {
                // pos[i]값이 pos[j] 값보다 더 크면 pos[j]의 연속된 값에 +1로 자신을 붙이겠다는 뜻.
                // 따라서 dp[i] = max(dp[i], dp[j]+1)이 된다.
                dp[pos[i]] = max(dp[pos[i]], dp[pos[j]]+1);
            }
        }
    }
    int maxLen = 0;
    for (int i=1; i<=n; i++){
        maxLen = max(maxLen, dp[i]);
    }

    cout << n - maxLen << "\n";
    return 0;
}
