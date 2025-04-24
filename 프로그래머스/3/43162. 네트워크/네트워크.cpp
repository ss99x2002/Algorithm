#include <string>
#include <vector>

using namespace std;

// 컴퓨터 A와 컴퓨터 B 직접적 연결
// 컴퓨터 B와 컴퓨터 C 직접적 연결
// A-C도 정보교환 가능.
// A-B-C 같은 네트워크상에 있음.

// 네트워크 갯수는?
// computers[i][j] = 1이면 i,j연결. 

// dfs 구현. 

vector<int>graph[201];
bool visited[201] = {false};
int cnt = 0;

void dfs(int node){
    visited[node] = true;
        for (int g : graph[node]){
        if (!visited[g]) dfs(g);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i=0; i<computers.size(); i++){
        for (int j=0; j<computers[i].size(); j++){
            if (computers[i][j] == 1 && i!=j){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    for (int i=0; i<n; i++){
        if (!visited[i]) {
            dfs(i);
            cnt ++;
        }
    }
    
    return cnt;
}