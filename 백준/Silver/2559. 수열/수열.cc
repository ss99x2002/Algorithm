#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


// 연속 며칠동안의 온도의 합이 가장 큰지 계산

int n,k;
int board[100001];
int ans = 0;
int maxAns;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> board[i];
    }

    for (int i=0; i<k; i++){
        ans = board[i] + ans;
    }

    maxAns = ans;

    for (int i=1; i<n-k+1; i++){
        ans =  ans - board[i-1] + board[i+k-1];
        maxAns = max(maxAns, ans);
    }

    cout << maxAns;
}