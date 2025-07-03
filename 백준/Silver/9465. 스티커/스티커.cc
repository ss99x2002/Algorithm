#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 두 변을 공유하지 않는 스티커 점수의 최댓값 출력

int t, n;
int dp[2][100001];
int arr[2][100001];


void init() {
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = arr[0][1];
    dp[1][1] = arr[1][1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<2; i++){
            for (int j=1; j<n+1; j++){
                cin >> arr[i][j];
            }
        }
        init();

        for (int j=2; j<n+1; j++){
            dp[0][j] = max(dp[1][j-2], dp[1][j-1]) + arr[0][j];
            dp[1][j] = max(dp[0][j-2], dp[0][j-1]) + arr[1][j];
        }

        cout << max(dp[0][n], dp[1][n]) << "\n";
    }
}