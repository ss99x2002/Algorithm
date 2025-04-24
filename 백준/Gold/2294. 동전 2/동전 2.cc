#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

// n가지 종류 동전 있다.
// 가치 합이 k원이 되도록 하는
// 동전의 갯수 최소는?

int n,k;
int dp[10001]; // dp[i] -> i원을 만드는데 필요한 동전의 수를 의미.
int coinV;
vector<int> coin;

int main(){
    cin >> n >> k;

    for (int i=1; i<=k; i++){
        dp[i] = 1e9;
    }

    for (int i=0; i<n; i++){
        cin >> coinV;
        coin.push_back(coinV);
    }

    dp[0] = 0;

    for (int i=1; i<=k; i++){
        for (auto c : coin){
            if (i-c >= 0 && dp[i - c] != 1e9) {
                dp[i] = min (dp[i], dp[i-c] +1);  // i-c 만든 상태에서 동전 하나 더 추가하면 i난들 수 있음.
            }
        }
    }

    if (dp[k] == 1e9) {
        cout << -1;
    }
    else {
        cout << dp[k] << "\n";
    }
}