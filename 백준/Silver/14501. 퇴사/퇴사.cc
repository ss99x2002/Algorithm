#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int n;
int T[1001];
int P[1001];
int dp[1001];

int main() {
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> T[i] >> P[i];
    }

    dp[0] = 0;
    for (int i=n; i>0; i--){ //날짜를 뒤에서 부터 새본다.
        if (i+T[i] > n+1){
            //상담 불가
            dp[i] = dp[i+1];
        } else {
            //상담 가능
            dp[i] = max(dp[i+1], dp[i+T[i]]+P[i]);
        }
    }

    cout << dp[1] << "\n";
}