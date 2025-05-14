#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 이중 우선순위 큐는 다음과 같은 자료구조 의미
// I 숫자 : 큐 숫자 삽입
// D 1 : 큐 최댓값 삭제
// D -1 : 큐 최솟값 삭제

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    vector<int> pq;
    
    int pushCnt = 0;
    for (int i=0; i<operations.size(); i++){
        if (operations[i] == "D 1"){
         // 큐 최대 삭제 
            if (!pq.empty()) pq.pop_back();
            
        } else if (operations[i] == "D -1"){
         // 큐 최소 삭제
            if (!pq.empty()) pq.erase(pq.begin(), pq.begin()+1);
            
        } else{
        // 큐 숫자 삽입
            pq.push_back(stoi(operations[i].substr(2)));
            sort(pq.begin(), pq.end()); //오름차순
        }
    }
    
    if (pq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    } else {
        int n = pq.size();
        answer.push_back(pq[n-1]);
        answer.push_back(pq[0]);
        
    }
    return answer;
}