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


bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int>b){
    if (a.first.second == b.first.second)
        return a.first.first < b.first.first;
    else
        return a.first.second < b.first.second;
}

int start,arrived,cnt;

vector<pair<pair<int,int>,int>> boxs;
int main() {
    cin >> n >> c;
    cin >> m;
    int answer = 0;

    for (int i=0; i<m; i++){
        cin >> start >> arrived >> cnt;
        boxs.push_back({{start,arrived},cnt});
    }
    sort(boxs.begin(), boxs.end(), comp);


    int load[2001] = {0};

    // (1-2,30) (3-4,40) (2-5,70) (1-6,40) (5-6,60)
    for (int i=0; i<boxs.size(); i++ ){
        int starts = boxs[i].first.first;
        int arv = boxs[i].first.second;
        int boxCnt = boxs[i].second;
        int maxTruck = 0;
        for (int j=starts; j<arv; j++){
            maxTruck = max(load[j],maxTruck);
            // 현재 실어야 할 택배가 가야하는 경로에서, 가장 많이 적재된 박스의 양을 확인
            // 이를 통해서 c-maxTruck으로 실을 수 있는 양을 파악하기 위함이다.
        }
        int capacity = min (boxCnt, c-maxTruck);
        for (int j=starts; j<arv; j++){
            // 도착지에는 더이상 더하지 않아서, 이를 실제로 박스가 내린 로직이라고 판단.
            load[j] = load[j] + capacity;
        }
        answer = answer + capacity;
    }
    cout << answer;
}
