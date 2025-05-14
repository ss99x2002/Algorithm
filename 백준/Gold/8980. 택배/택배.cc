#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

// 직선 도로상 왼쪽부터 오른쪽 1번부터 차례대로 번호 있다.
// 본부에서 출발해서 1번 마을부터 마지막까지 오른쪽으로 가면서 마을 물건 배송

// 각 마을은 배송할 물건을 박스에 넣어 보내며,
// 본부에서는 (박스를 보내는 마을 번호, 박스를 받는 마을 번호, 보낼 박스 수) 알고있다.
// 트럭에 최대로 실을 수 있는 박스 개수 -> 즉 트럭 용량 존재.

// 1. 박스를 실으면, 이 박스는 받는 마을에서만 내린다.
// 2. 트럭은 지나온 마을로 되돌아가지 않는다. (즉 왼->오로만 이동)
// 3. 박스들 중 일부만 배송할 수 있다.

// 트럭 한대로 배송할 수 있는 최대 박스 수 구하기
// 항상 : 받는 마을번호 > 보내는 마을 번호

int n,c,m; //n=마을수, c=트럭용량, m=박스정보수

vector<pair<int,int>> boxs[20001];

bool comp(pair<int,int> a, pair<int,int> b){
   if (a.first != b.first){
       return a.first < b.first;
   }
   return a.second > b.second;
}

int start,arrived,cnt;

int main() {
    cin >> n >> c;
    cin >> m;
    int answer = 0;

    for (int i=0; i<m; i++){
        cin >> start >> arrived >> cnt;
        boxs[start].push_back({arrived,cnt});
    }

    for (int i=1; i<n+1; i++){
        sort(boxs[i].begin(), boxs[i].end(), comp);
    }

    int curW = 0; //현재 적재된 박스 수
    int res = c;
    int load[20001] = {0};
    for (int i=1; i<=n; i++){
        if (load[i] != 0) curW = curW - load[i]; // j마을 도착했는데, j마을에 줘야하는게 있다.
        for (int j=0; j<boxs[i].size(); j++){
           res = c-curW; //현재 적재 가능한 남은 박스 수
            if (res >= boxs[i][j].second) {
                curW = curW + boxs[i][j].second;
                load[boxs[i][j].first] = boxs[i][j].second + load[boxs[i][j].first]; //j마을로 가는 박스 수
            } else {
                    curW = curW + res; // 만약 남은 수 보다 second가 더 많으면, 남은거 만큼만 담도록
                    load[boxs[i][j].first] = res +  load[boxs[i][j].first]; // 남은거 만큼 j마을로 감.
            }
        }
    }

    for (int i=1; i<=n; i++){
        answer = answer + load[i];
    }
    cout << answer;
}
