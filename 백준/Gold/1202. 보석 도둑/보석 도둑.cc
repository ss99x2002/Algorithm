#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


// 상덕이가 털 보석점은 보석이 총 n개 있다.
// 각 보석은 무게 m, 가격 v 갖고있다.
// 상덕이는 가방 k개를 갖고 있고, 각 가방에 담을 수 있는 최대 무게는 c다.
// 가방에는 한개의 보석만 넣을 수 있다.

// 상덕이가 훔칠 수 있는 보석의 최대 가격 구하시오.

// 즉 비싼 보석들만 훔쳐야 함.

int n, k;
vector<pair<int, int>>jewel;
vector<long long> bags;
long long m, v; //무게, 가격
long long c; //가방 무게


struct comp {
    bool operator()(int a, int b) {
        return a < b;
    }
};

priority_queue<int, vector<int>, comp> pq;

bool compS(pair<int,int> a, pair<int,int> b){
    if (a.first != b.first) {
        return a.first < b.first;
    }
}

int main() {
    cin >> n >> k; // 보석 수, 가방 k

    for (int i = 1; i <= n; i++) { // 1-based
        cin >> m >> v;
        jewel.push_back({m, v});
    }

    for (int i = 1; i <= k; i++) { // 1-based
        cin >> c;
        bags.push_back(c);
    }

    sort(bags.begin(), bags.end()); // 오름차순
    sort(jewel.begin(), jewel.end(), compS); //무게 오름차순

    long long maxAnswer = 0;
    int jewelIdx = 0;
    for (long long i : bags) {
        while(jewelIdx < n && jewel[jewelIdx].first <= i) {
            pq.push(jewel[jewelIdx].second);
            jewelIdx++;
        }

        if (!pq.empty()){
          //  cout << "pq.top() == " << pq.top() << "\n";
            maxAnswer = maxAnswer + pq.top();
            pq.pop();
        }
    }

    cout << maxAnswer;

    return 0;
}