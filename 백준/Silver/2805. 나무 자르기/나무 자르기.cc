#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

// 최적화 문제
// 적어도 M미터의 나무를 집에 가져가기 위해 절단기 설정 높이의 최댓값을 구하자.

// 결정 문제
// 절단기의 높이가 X일 때 조각의 합이 M이 되는가?

// -> 절단기 높이의 최댓값을 구하면 됨. 즉 target이 되는 최댓값.

ll N,M; // n= 나무의 수, m= 가져가려고 하는 나무의 길이
ll nArr [1000001]; // 나무 길이 모음

bool solve (ll x) {
    ll cur = 0;
    for (int i=0; i<N; i++) {
       if (nArr[i]-x < 0) {
           cur = cur + 0;
       }
       else {
           cur = cur+nArr[i]-x;
       }
    }
    return cur >= M;
}

int main(){
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> nArr[i]; //나무 입력
    }

    sort (nArr, nArr + N);

    ll st = 0; // st와 en은 절단기의 높이 .. 즉 절단기의 높이가 0인 (자르지 않는 경우)도 포함해야 함.
    ll en = *max_element(nArr, nArr +N);

    while(st < en) {
        ll mid = (st+en+1)/2;
        if (solve(mid)) st = mid;
        else en = mid -1;
    }
    cout << st;
}