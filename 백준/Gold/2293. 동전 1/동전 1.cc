#include <iostream>

using namespace std;

// n가지 종류의 동전이 있을 때, 가치의 합이 k원이 되도록 하고싶다.
// 그 경우의 수를 구하시오
// 사용 동전의 구성이 같은데, 순서만 다른 경우 => 같은거다. (조합)

// 0.5초 .. -> 백트래킹 조합 불가능

int n,k;
int coins[101];
int dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >>n >> k;

    for (int i=0; i<n; i++){
        cin >> coins[i];
    }

    dp[0] = 1; //아무것도 안사용하면 0원은 1경우의 수 있음.
    for (int i=0; i<n; i++){
        int curCoin = coins[i];

        for (int j=curCoin; j<=k; j++){
            dp[j] = dp[j] + dp[j-curCoin];
            //이전 코인에서 coin만 더하면되기 때문에
        }
    }

    cout << dp[k] << "\n";


}