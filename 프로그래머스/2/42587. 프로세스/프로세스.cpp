#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

// 큐(fifo)에서 프로세스 하나 꺼냅니다.
// 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스 다시 큐에 넣는다.
// 만약 그런 프로세스 없다면 방금 꺼낸 프로세스를 실행
// 한번 실행한 프로세스는 큐에 안넣고 그대로 종료

// 우선순위는 숫자 클수록 높은거였음 !!

priority_queue<pair<int,int>> pq;
queue<pair<int,int>> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for (int i=0; i<priorities.size(); i++){
        q.push({priorities[i], i});
        pq.push({priorities[i],i});
    }
    
    int cnt =0;
    while(!q.empty()){
        int priority = q.front().first;
        int index = q.front().second;
        q.pop();
        
        if (priority == pq.top().first){
            pq.pop();
            cnt++;
            if (index == location){
                return cnt;
            }
        } else {
            q.push({priority,index});
        }
        
    }

    
    return answer;
}

// 1,1,9,1,1,1
// (2,9), (3,1), 