#include <string>
#include <vector>
#include <queue>
#include <iostream>

// 트럭 여러대가 다리를 정해진 순서대로 건녀려 한다
// 모든 트럭이 다리를 건너려면 최소 몇초가 걸리는지 구하자.
// 다리에는 최대 bridge_legth대 올라갈 수 있음
// 다리는 weight이하 견딜 수 있음

using namespace std;

queue<int> q;

int solution(int blen, int weight, vector<int> truck_weight) {
    int answer = 0;
    for (int i=0; i<blen; i++){
        q.push(0); //다리 위에 빈공간이 됨.
    }
    int sum = 0;
    int nextIdx = 0;
    while(!q.empty()){
        answer ++; // 초 증가
        sum = sum-q.front();
        q.pop();
        
        if (nextIdx < truck_weight.size()){
            if (sum + truck_weight[nextIdx] <= weight){
                sum = sum + truck_weight[nextIdx];
                q.push(truck_weight[nextIdx]);
                nextIdx ++;
            }
            else {
                q.push(0);
            }
        }
    }
    
    return answer;
    
}