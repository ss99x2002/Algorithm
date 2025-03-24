#include <string>
#include <vector>
#include <stack>

using namespace std;

// a와 b가 직접적으로 연결, b와 c연결 -> a,c 연결 가능 -> a,b,c같은 네트워크상
// 컴터갯수 n, 연결 2차원 배열 computers
// 출력 : 네트워크의 수 return 

// dfs 이용. 
// 컴퓨터 i번과 j번 연결되어 있으면 computers[i][j] = 1로 표기
// 항상 computer[i][i] = 1 

// dfs -> 스택, 재귀
// bfs -> 큐 이용

int cnt = 0;
int visited[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i=0; i<n; i++){
        if (!visited[i]){
            stack<int> s;
            s.push(i);
            visited[i] = true;
            while(!s.empty()){
                int cur = s.top();
                s.pop();
                for (int next = 0; next < n; next ++){
                    if (computers[cur][next] == 1 && i!=next && !visited[next] ) {
                        visited[next] = 1;
                        s.push(next);
                    }
                }
            }
            cnt ++;
        }
        
    }
    return cnt;
}