#include <string>
#include <vector>
#include <queue>
#include <cmath>
// n개의 송전탑 전선을 통해 하나의 트리 형태로 연결
// 이 전선들 중 하나 끊어서 네트워크를 2개로 분할
// 두 전력망이 갖는 송전탑의 갯수를 최대한 비슷하게 맞추고자 함.
// 송전탑 n, 전성정보 wires
// 전선들 중 하나를 끊어서 송전탑 개수 가능한 비슷하도록 
// 두 전력망이 갖는 송전탑 개수 차이 (절대값) return

using namespace std;

// 해결 방법
// 전선 정보 다 탐색해서 -> 하나씩 끊어보고
// 분할된 두개 pair값의 절댓값이 적은걸로 선택하도록 진행. 
int cnt;
bool visited[101];
vector<int> graph[101];

void bfs (int v1, int v2){
    queue<int> q;
    q.push(v1);
    visited[v1] = true;
    visited[v2] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();  
        for (int i=0; i<graph[cur].size(); i++) {
            int node2 = graph[cur][i];
            if (visited[node2]) continue;
            cnt ++;
            q.push(node2);
            visited[node2] = true;
        }
    }
}

void initVisited(){
    for (int i=0; i<101; i++){
        visited[i] = false; 
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for (auto wire: wires){
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);
    }
    
    for (auto wire:wires) {
        cnt = 1; // 자기 자신은 1개로 포함해야 함. 
        int v1 = wire[0];
        int v2 = wire[1];
        bfs(v1,v2);
        initVisited();
        answer = min(answer,abs(n-2*cnt));
    }
    return answer;
}