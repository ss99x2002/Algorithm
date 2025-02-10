#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

// ### 최적화 문제
// M명에게 나눠줄 수 있는 최대 길이
// ### 결정 문제
// 인당 과자가 X일 때, 과자 조각 M개 이상인가 아닌가?

int M, N; //m=조카, n=과자
int nArr [1000001];

bool solve(ll x){
    ll cur = 0;
    for (int i=0; i<N; i++) {
        cur += nArr[i]/x;
    }
    return cur >= M;
}

int main(){
  cin >> M >> N;
  for (int i=0; i<N; i++) {
      cin >> nArr[i]; // 과자.
  }

  sort(nArr, nArr+N);

  ll st = 0;
  ll en = *max_element(nArr, nArr+N);
  bool flag = false;

  while(st < en) {
      ll mid = (st+en+1)/2;
      if (solve(mid)) {
          st = mid;
          flag = true;
      }
      else en = mid -1;
  }
  if (flag == false) {
      cout << 0;
  }
  else {
      cout << st;
  }
}