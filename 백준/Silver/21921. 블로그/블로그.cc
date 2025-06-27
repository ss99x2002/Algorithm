#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// 블로그 시작 n일동안
// x일동안 가장 많이 들어온 방문자 수와 그 기간 알고 싶다.
// x일 동안 가장 많이 들어온 방문자 수와 기간이 몇 개인지 구하기.

// 최대 방문자 수가 0이면 SAD 출력

int n,x;
int num;
vector<int> a;
vector<long long> sums;
long long ans;
long long maxAns;
int cnt = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;

    for (int i=0; i<n; i++){
        cin >> num;
        a.push_back(num);
    }

    for (int i=0; i<x; i++){
        ans = ans + a[i];
    }

    sums.push_back(ans);
    maxAns = ans;


    for (int i=1; i<n-x+1; i++){
        ans = ans - a[i-1] + a[i+x-1];
        sums.push_back(ans);
        maxAns = max(maxAns,ans);
    }

    for (int i=0; i<sums.size(); i++){
        if (maxAns == sums[i]) {
            cnt ++;
        }
    }

    if (maxAns == 0){
        cout << "SAD" << "\n";
        return 0;
    }
    else {
        cout << maxAns << "\n" << cnt;
    }
}