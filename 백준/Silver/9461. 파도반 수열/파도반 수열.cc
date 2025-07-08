#include <iostream>

using namespace std;

// 나선에서 가장 긴 변을 k라 할 때, 그 변의 길이가 k인 정삼각형을 추가한다.
// P(N)은 나선에 있는 정삼각형의 변의 길이이다.

// P(1)부터 P(10)까지 첫 10개의 숫자는 1,1,1,2,2,3,4,5,7,9이다.
// N이 주어질 때, P(N) 구하는 프로그램은?

int t, n;
long long dp[101];

void init() {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    init();

    while (t--) {
        cin >> n;
        for (int i=6; i<=n; i++){
           dp[i] = dp[i-1] + dp[i-5];
        }
        cout << dp[n] << "\n";
    }

    return 0;
}