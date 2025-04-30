#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

// n개의 꽃이 있는데, 꽃은 모두 같은 해에 피어서 같은 해에 진다.
// 하나의 꽃은 피는 날과 지는 날이 정해져 있다.

// ex. 5월 8일에 피어서 6월 13일에 지는 꽃은 -> 12일까지 피어있다가 13일날 짐.
// 4,6,9,11 = 30일까지
// 1,3,5,7,8,10,12월 = 31일까지
// 2 = 28까지

// 조건으로 꽃 선택
// 공주가 가장 좋아하는 계절인 3월 1일부터 ~ 11월 30일까지 매일 꽃이 한가지 이상 피어야 함.
// 정원에 심는 꽃들의 수는 가능한 적게

// N개 꽃 중 선택한 꽃들의 최소 갯수?

int n;
// 꽃 피는 날이랑 지는 날 나옴
int startM,startD;
int endM,endD;
// 10^7정도는 기본 메모리 제한 범위 가능.

int answer = 0;
int monthDay[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


bool comp(pair<int,int> a, pair<int,int> b ){
    if (a.first == b.first){
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

vector<pair<int,int>> flower;

int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> startM >> startD >> endM >> endD;
        flower.push_back( {(startM * 100 + startD), (endM * 100 + endD)});
    }

    // 조건 3월 1일부터 11월 30일까지 매일 꽃이 한가지 이상 있어야 한다.
    // 즉 3월 1일보다 작거나, 11월 30일 보다 크면 쓸모 없음. -> 버려야 함.

    sort(flower.begin(), flower.end(), comp);

    // 시작 날짜 오름차순,
    // 시작이 같다면 끝나는 날짜 내림차순.

    int st = 301;
    int ed = 1130;
    int idx = 0; // 한번보관용 인덱스
    int cnt = 0;

    while(st <= ed){
        int bestEnd = st;
        while(idx < n && flower[idx].first <= st){
            bestEnd = max(bestEnd, flower[idx].second);
            idx ++;
        }

        if (bestEnd == st) {
            cout << 0;
            return 0;
        }

        st = bestEnd;
        cnt ++;
    }

    // 정원에 심는 꽃의 수는 가능한 적게 한다.
    cout << cnt;
    
}
