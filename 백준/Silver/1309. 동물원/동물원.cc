#include <iostream>

using namespace std;

int n;
int dp[100001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // dp[i][n] = i행에 동물을 놓는 방법의 횟수
    // 0: O,X
    // 1: X,O
    // 2: X,X (둘다 안 놓음)
    
    // ex) dp[1][0] = 1행에 O,X로 두었다는 뜻.
    // 따라서 다음 행에 dp[i][0] = dp[i-1][1] + dp[i-1][2]
    // dp[i][2] = dp[i-1][1] + dp[i-1][2] + dp[i-1][0] //이전에 뒀든 안뒀든 상관없이 다 가능
    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for (int i=2; i<=n; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]+dp[i-1][2]) % 9901;
    }

    cout << (dp[n][0] + dp[n][1] + dp[n][2])%9901;
}