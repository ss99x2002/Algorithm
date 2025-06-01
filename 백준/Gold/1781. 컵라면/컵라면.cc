#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 상욱 조교는 동호에게 n개 문제 줌.
// 각각 문제 풀었을 때 컵라면 몇개 줄것인지 제시.
// 각각 문제에 대한 데드라인을 정했다.

// 동호가 받을 수 있는 최대 컵라면의 수
// 문제를 푸는데는 단위시간 1이 걸리며, 모든 문제의 데드라인은 n이하 자연수다.

int n;

int deadline, ramen;
vector<int> questions[200001];

struct comp {
    bool operator()(const int a, const int b) const {
        return a < b; // a.second < b.second 이면 b가 우선
    }
};

priority_queue<int, vector<int>, comp> pq;

int main() {

    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> deadline >> ramen;
        questions[deadline].push_back(ramen);
    }
    int times = n;
    int maxAnswer = 0;
    while(times >= 1) {
        if (!questions[times].empty()){
            for (int i : questions[times]){
                pq.push(i);
            }
        }
        if(!pq.empty()){
            maxAnswer = maxAnswer +pq.top();
            pq.pop();
        }
        times --;
    }

    cout << maxAnswer;

    return 0;
}