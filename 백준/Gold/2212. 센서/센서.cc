#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 고속도로 위에 n개의 센서를 설치하였다.
// 센서들의 자료를 수집하기 위해, 최대 k개의 집중국을 세울 수 있다.

// n개의 센서는 적어도 하나의 집중국과는 통신가능 해야하며
// 각 집중국의 수신 가능 영역의 길이의 합을 최소화

int n,k,input;
vector<int> sensor;
vector<pair<int,int>> diff;

bool comp(pair<int,int> a, pair<int,int> b) {
    if (a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> k;

    for (int i=0; i<n; i++){
        cin >> input;
        sensor.push_back(input);
    }

    sort(sensor.begin(), sensor.end());


    // k개의 집중국의 수신 가능한 길이 합의 최소
    
    if (n <= k){
        cout << 0 << "\n";
        return 0;
    }

    for (int i=0; i<n-1; i++){
        diff.push_back({sensor[i],sensor[i+1]-sensor[i]});
        // 시작지점, 나아갈 거리
    }

    sort(diff.begin(), diff.end(), comp);

    int total = sensor[n-1] - sensor[0];
    for (int i=0; i<k-1; i++){
        total = total-diff[i].second;
    }

    cout << total << "\n";

    return 0;
}