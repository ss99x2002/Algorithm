#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 우선순위 디스크 컨트롤러 작동방식
// 작업 번호, 요청시각, 소요시간 저장해두는 대기 큐 있음 -> 처음에 비어있다.
// 하드디스크 작업 x, 대기큐 원소 있으면 -> 우선순위 높은거 대기큐에서 꺼내서 작업시킴

// (우선순위) 소요시간이 짧은것 > 작업 요청 시간이 빠른것 > 작업 번호가 작은것 

// 작업 하나 시작하면 마칠 때까지 그 작업만 수행
// 
// 각 작업에 대한 [작업 요청 시점, 작업 소요시간] = jobs
// 모든 요청 작업 시간의 평균 return solution 


priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    int answer = 0;
    int i = 0;
    int sum = 0;
    int times = 0;
    int count = 0;
    while(count< jobs.size() ){
        while(i < jobs.size() && jobs[i][0] <= times) {
            pq.push({jobs[i][1], jobs[i][0]});
            i ++;
        }

        if (!pq.empty()){
            times = pq.top().first + times;
            sum = sum + (times - pq.top().second);
            pq.pop();
            count ++;
        }
        else {
            times = jobs[i][0];
        }
    }
     answer = sum/(jobs.size());
    return answer;
}


/* 
1. jobs를 요청 시간 기준으로 정렬
2. 현재 실행 중인 작업이 끝날 때까지 들어오는 작업을 우선순위 큐에 넣기
3. 우선순위 큐에서 가장 짧은 작업을 선택하여 수행
4. 작업 수행 후, 현재 시간을 업데이트
5. 모든 작업이 끝날 때까지 반복 */ 