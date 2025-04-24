#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 각 그래프 노드에 1 ~ n 번호 적혀있음.
// 1번 노드에서 가장 멀리 떨어진 노드의 갯수 구하려 함.
// 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드들을 의미. 

vector<int> graph[20001];
int dist[20001]; //1에서부터 거리 
int maxAnswer = 0;
int cnt = 0;
int visited[20001];
int copyN;
int maxV = -1;

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (auto g : graph[cur]){
            if (visited[g] != -1) continue;
            visited[g] = visited[cur] + 1;
            q.push(g);
        }      
    }
}


void findMax(){
    for (int i=0; i<=copyN; i++){
        maxV = max(maxV, visited[i]);
    }
    
    cout << "--" << maxV << "\n";
    
     for (int i=0; i<=copyN; i++){
        if (visited[i] == maxV){
            maxAnswer ++;
        }
    }
    
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    copyN = n;
    
    for (int i=0; i<=n; i++){
        visited[i] = -1;
    }
    for (int i=0; i< edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs(1);
    findMax();
    
    return maxAnswer;
}