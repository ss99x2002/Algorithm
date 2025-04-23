#include <string>
#include <vector>
#include <queue>

using namespace std;

// 가장 왼쪽 위, (1,1)
// 오른쪽 학교는 (m,n)

// 물에 잠기지 않은 지역을 통해 학교가려 함.
// 어떤 좌표가 물에 잠겨있을 때, 
// 오른쪽과 아래쪽으로만 움직여서 집에서 학교 갈 수 있는 최단경로 갯수
// 를 1,000,000,007로 나눈 나머지 return 

int dx[2] = {0,1}; //아래
int dy[2] = {1,0}; // 오른

int board[101][101];
int dist[101][101];
int countPath[101][101];
bool visited[101][101];
int copyM;
int copyN;

void dfs(){
    queue<pair<int,int>> q;
    q.push({1,1});
    dist[1][1] = 0;
    countPath[1][1] = 1;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for (int i=0; i<2; i++){
            int curX = cur.first + dx[i];
            int curY = cur.second + dy[i];            
            if (curX < 1 || curY < 1 || curX > copyM || curY > copyN) continue;
            if (board[curX][curY] == -1) continue;
            if (dist[curX][curY] == -1) {
                dist[curX][curY] = dist[cur.first][cur.second] + 1;
                countPath[curX][curY] = countPath[cur.first][cur.second];
                q.push({curX,curY});
            } else if (dist[curX][curY] == dist[cur.first][cur.second] + 1) {
                countPath[curX][curY] = (countPath[curX][curY] + countPath[cur.first][cur.second]) % 1000000007;
            }
        }
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    copyM = m;
    copyN = n;
    int answer = 0;
    for (auto &p : puddles){
            board[p[0]][p[1]] = -1;
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            dist[i][j] = -1;
            countPath[i][j] = 0;
        }
    }
    dfs();
    answer = countPath[m][n];
    return answer;
}