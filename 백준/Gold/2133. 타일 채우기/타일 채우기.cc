#include <iostream>

using namespace std;

// 3*N 크기의 벽을 2*1, 1*2 타일로 채우는 경우의 수


long long dp[10001];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

  dp[0] = 1;
  dp[1] = 0;
  dp[2] = 3;

    cin >> n;

    if(n%2 != 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    // 간과한 부분 
    // n>=4 일 때 2단위마다, 특수 모양 생김
    // 처음에 2,4 모양만으로 로직을 짜고, 중복 발생 + 특수모양 생각 x 갯수 누락 

    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3; // 기본 3가지 패턴을 오른쪽 끝에 붙인 경우

        // 특수한 블록 조합:
        // dp[j]까지 타일링한 경우의 수(dp[j]) 각각에
        // 뒤쪽에 길이 (i - j)의 특수 블록 2가지 중 하나를 붙이는 방식
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;

            // 예: i = 10이면
            // dp[10] += dp[6] * 2; // dp[6]까지 채운 뒤, 길이 4짜리 특수 구조 2개 중 하나를 붙이는 방식
        }
    }
    
    cout << dp[n] << "\n";

}