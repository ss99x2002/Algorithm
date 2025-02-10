#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

//### 최적화 문제
//N개를 만들 수 있는 랜선의 최대 길이
//### 결정 문제
//랜선의 길이가 X일 때 랜선이 N개 이상인가 아닌가?

//랜선의 길이는 231-1보다 작거나 같은 자연수이다.

int k,n; // k=랜선 , n= 필요 나누는 수
int kArr[10001]; // 기존 랜선들

bool solve(ll x) {
    ll cur = 0;
    for (int i=0; i<k; i++) {
        cur += kArr[i]/x; // 다 더하고 나누나, 나눠서 더하나 동일.
    }
    return cur >=n; //n개 이상인가?
}


int main(){
    cin >> k >> n;
    for (int i=0; i<k; i++){
        cin >> kArr[i];
    }

    ll st = 1;
    ll en = 0x7fffffff; // 2^31-1

    while(st < en) {
        ll mid = (st+en+1)/2;
        if (solve(mid)) st = mid; //st를 땡김 -> 즉 최댓값 upper를 구하겠다는 뜻.
        else en = mid -1;
    }
    cout << st;
}