#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

// 입력 예시
//[[0, 3], [1, 9], [3, 5]]
// (작업 시작 시간, 작업 소요 시간)

struct cmp {
    bool operator()(const pair<int,int> a, const pair<int,int> b) const {
        if(a.second != b.second){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};


bool jobsComp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx =0;
    int curTime = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    // pq의 비교함수를 줘서, 넣기만해도 작업간 우선순위를 결정할 수 있도록 한다.
    // pq의 비교함수는 struct로 구현된다. 
    
    sort(jobs.begin(), jobs.end(), jobsComp);
    // job 자체가 (2,6) (0,3) (1,9) 처럼 시작 순서가 뒤죽박죽 오는 케이스가 있기 때문에 sort 필요.

    while(idx < jobs.size() || !pq.empty()){
        // 대기열 비어있으면, 다음 도착 시간으로 점프
        if (pq.empty()){
           curTime = max(curTime, jobs[idx][0]); 
           // 도착시간으로 바로 점프해서 -> 해당 도착시간 전 작업들을 살필 수 있도록 한다. 
        }
        
        // 지금 시각까지 도착한 작업 모두 대기열에 추가
        // 조건 따지지 않고 추가하면 된다 -> 나오는 작업 조건은 pq comp에 정의해둠.
        while(idx < jobs.size() && jobs[idx][0] <= curTime){
           int arrive = jobs[idx][0];
           int duration = jobs[idx][1];
           pq.push({arrive,duration});
           idx ++;
        }   
        // 우선순위 높은 작업 선택 후, 해당 작업이 기다린 시간 계산 및 처리 
        auto [arrive, duration]  = pq.top();
        pq.pop();
        curTime = curTime + duration;
        answer = answer + (curTime - arrive);
    }
    
    return (int)answer/jobs.size();
}