#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

// 흙으로 된 비밀길 위에 폭우가 내려서 n개 물웅덩이 생겼다.
// 물 웅덩이 덮을 수 있는 길이 l 널빤지 충분
// 이들로 다리를 넘어서 물웅덩이 모두 덮으려 한다.

// 모든 물 웅덩이를 덮기 위해 필요한 널빤지 최소 갯수?

int n;
int l;
int startIdx, endIdx;

stack<int> a;

vector<pair<int,int>> road;

bool comp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

int main() {
    cin >> n >> l;

    int minAnswer = 0;

    for (int i=1; i<=n; i++){
        cin >> startIdx >> endIdx;
        road.push_back({startIdx,endIdx});
    }

    sort(road.begin(), road.end());

    int next = 0;
    for (int i=0; i<road.size(); i++) {
        if (next < road[i].first) {
            next = road[i].first;
        }

        while(next < road[i].second) {
            next = next + l;
            minAnswer ++;
        }
    }



    cout << minAnswer;
    return 0;
}