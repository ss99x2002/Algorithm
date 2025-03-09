#include <iostream>
#include <algorithm>
using namespace std;


// 나무 2개중 하나의 나무에서 열매가 떨어진다.
// 떨어지는 순간 자두가 나무 아래에 서있으면 그 열매를 받아먹을 수 있다.
// 다른 나무에서 떨어지는 나무까지 1초보다 빠르게 움직일 수 있다.

int t,w;
int treeNum;
// t = t초동안 자두가 떨어진다.
// w = 사람 자두가 최대 w번만 움직이고 싶어 한다.

// 입력 : 열매가 떨어지는 나무의 번호 1, 2 로 나옴.
// 출력 : 사람 자두가 받을 수 있는 자두의 최대 갯수는?

int dp[2][31][1001];
// 자두의 위치, 이동횟수, 흐르는 시간 = 받은 자두의 수
int treeList[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;
    int cntW = 0;

    for (int i=1; i<=t; i++){
        cin >> treeList[i];
    }

    for (int j=0; j<=w; j++){
        for (int i=1; i<=t; i++){
            if (j==0) {
                dp[0][j][i] = dp[0][j][i-1] + (treeList[i] == 1);
            }
            else{
                dp[0][j][i] = max(dp[0][j][i-1] + (treeList[i]==1), dp[1][j-1][i-1]+(treeList[i] == 1));
                dp[1][j][i] = max(dp[1][j][i-1] +(treeList[i] == 2), dp[0][j-1][i-1] + (treeList[i] == 2));
            }
        }
    }

    int ans =0;
    for (int i=0; i<2; i++){
        for (int j=0; j<=w; j++){
            ans = max(ans, dp[i][j][t]);
        }
    }

    cout << ans;
}