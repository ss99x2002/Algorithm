#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 야근 피로도 = (각 남은 작업량 제곱)의 합
// N시간 동안 야근 피로도 최소화

// 1시간동안 작업량 1만큼 처리가능 할 때,
// 퇴근까지 N시간과, 각 일에 대한 작업량 works에 대해
// 야근 피로도 최소화한 값 리턴

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue <int> pq;
    
    for (int i=0; i<works.size(); i++){
        pq.push(works[i]);
    }
    
    
    for (int i=0; i<n; i++){
        long long tops = pq.top();
        pq.pop();
        tops = tops-1;
        pq.push(tops);
    }
    
    while(!pq.empty()){
        if(pq.top() < 0) {
            break;
        }
        answer = answer + (pq.top() * pq.top());
        pq.pop();
    }
    
    return answer;
}