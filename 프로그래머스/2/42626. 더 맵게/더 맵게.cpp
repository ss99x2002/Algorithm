#include <string>
#include <vector>
#include <queue>

using namespace std;

// 모든 음식의 스코빌 지수를 k이상으로 만들고 싶다.
// 섞은 음식 스코빌 지수 
// = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

// scoville -> 모든 음식의 스코빌 지수 담은 배열
// 원하는 스코빌 지수 K
// 모든 음식 스코빌 지수 K 이상으로 만들기 위해 섞어야 하는 최소 횟수 return 

priority_queue<int, vector<int>,greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for (int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    int cnt = 0;
    while(pq.size() > 1){
        int newK = pq.top();
        pq.pop();
        if (!pq.empty() && newK < K){
            int second = pq.top();
            pq.pop();
            newK = newK + second *2;
            cnt ++;
            pq.push(newK);
        }
    }
    return pq.top() >= K ? cnt : -1;
} 