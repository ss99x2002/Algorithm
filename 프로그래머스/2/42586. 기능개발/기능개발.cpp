#include <string>
#include <vector>
#include <iostream>
#include <queue> //first in first out
#include <cmath>

using namespace std;
// 기능이 앞에 기능보다 먼저 개발될 수 있고, 뒤에있는 기능은 앞에 있는 기능이 배포될 때 함께 배포.
// 배포되어야 하는 순서대로 작업 진도 배열 progress
// 각 작업 개발 속도배열 speeds

// 배포는 하루에 한번만, ex. 95%작업 하루 4%라면 이틀뒤에 배포 가능. 

// 각 배포마다 몇개의 기능이 배포되는지 return 

queue<long long> work;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for (long long i=0; i<progresses.size(); i++){
        work.push(ceil(float(100-(progresses[i]))/speeds[i]));
        // ex) {30,30} -> 30 + 30*day = 100 // day = 100-progress/speed 
    }
    while(!work.empty()){
        long long first = work.front();
        cout << "first = ** " << first << "\n";
        work.pop();
        int cnt = 1;
        while(!work.empty() && first >= work.front()){
            work.pop();
            cnt ++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}