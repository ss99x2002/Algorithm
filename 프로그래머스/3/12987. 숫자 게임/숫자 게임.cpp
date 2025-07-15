#include <string>
#include <vector>
#include <stack>
#include <algorithm>
// 모든 사원이 무작위로 자연수 하나씩 부여받음
// 각 사원은 딱 한번씩 경기한다.

// 각 경기마다 A팀에서 한 사원, B팀에서 한 사원 서로의 수 공개
// 그때 숫자가 큰 쪽이 승리, 승리한 사원쪽이 승점 1점 얻음 -> 같으면 누구도 승점 x

// A팀의 출전선수의 순서가 공개되어있을 때,B팀이 얻을 수 있는 최대 승점을 return 

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(),comp);

    stack<int> s;
    
    for (int i=0; i<A.size(); i++){
        s.push(A[i]);
    }
    
    int i = 0;
     while(!s.empty() && i < B.size()) {
        if (s.top() < B[i]){
            answer ++;
            s.pop();
            i++;
        }
        else {
            s.pop();
        }
    }
    
    
    return answer;
}