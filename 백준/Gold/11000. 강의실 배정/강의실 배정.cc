#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector <pair<int, int>> v;
    priority_queue<int,vector<int>,greater<int>> pq; //오름차순 정렬 
    int N;
    int s, e;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        v.push_back({ s,e });
    }
    sort(v.begin(), v.end()); // 회의 시작 시간 순으로 정렬
    
    pq.push(v.front().second); //
    for (int i = 1; i < N; i++) {
        if (v[i].first < pq.top()) {
            pq.push(v[i].second); 
        }
        else {
            pq.pop();
            pq.push(v[i].second);
        }
    }
    cout << pq.size() << "\n";
}
