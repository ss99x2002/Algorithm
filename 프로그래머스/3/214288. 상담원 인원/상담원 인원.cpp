#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
int copyK;
vector<vector<int>> mentoNums;
// [[0,1,1], [0,2,0]] 이런식으로 각 유형별 멘토 경우의수를 모두 적어둔 배열을 의미한다. 

void backTraking(int remain, int idx, vector<int> mentos) {
    if (remain <= 0){
        mentoNums.push_back(mentos);
        return;
    }
    
    for (int i=idx; i<=copyK; i++){
        mentos[i]++;
        backTraking(remain-1,i, mentos);
        mentos[i]--;
    }
}

int simulation(vector<int> mento, vector<vector<int>> reqs){
    int result =0;
    
    // Pq의 기본값은 max heap, 따라서 min Heap으로 만들기 위해 greater 필요.
    priority_queue<int, vector<int>, greater<int>> pq[copyK+1];
    
    for (int i=1; i<=copyK; i++){
        for (int j=0; j<mento[i]; j++){
            pq[i].push(0);
            // 초기 경우의수 멘토 수 만큼 0으로 넣어서 칸 만들기.
        }
    }
    
    for (auto req : reqs){
        int startT = req[0]; //상담 요청 시각
        int times = req[1]; // 상담 걸리는 시간
        int type = req[2]; // 상담 유형
        
        int picked = pq[type].top();
        pq[type].pop();
        
        if (picked > startT){
            result = result + (picked-startT);
            pq[type].push(picked+times);
        }
        
        else if (picked == startT) {
            pq[type].push(picked+times);
        }
        
        else {
            pq[type].push(startT + times);
        }
    }
    
    return result;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 99999999;
    copyK = k;
    
    vector<int> mentos(k+1,1); // 1~k까지 1로 채우기 위함. 
    backTraking(n-k, 1, mentos);
        
    for (auto m : mentoNums){
        // 각 배정한 경우의 수에 따른 -> 대기 시간 계산
        answer = min(answer, simulation(m,reqs));
    }
        
    return answer;
}