#include<vector>
#include <queue>
#include <iostream>
using namespace std;

// 상대팀 진영에 최대한 빨리 도착하는 것이 유리
// 검은색 = 벽 == 갈 수 없음
// 흰색 == 갈 수 있음.
// 캐리겉 동,서,남,북

// 상대팀 진영에 도착하기 위해 지나가야 하는 칸의 갯수 최솟값은?
// 상대 팀 진영에 도착 불가능 할 때 -1 return;

// 0 = 벽, 1= 벽 없음.
// 처음 캐릭터는 1,1 상대편 진영은 n,m에 위치.
int board[101][101];
bool visited[101][101];
int dist[101][101];
int dx[4] = {0, -1,0,1};
int dy[4] = {1,0,-1,0};

int n,m;

void bfs(int startX, int startY){
    queue<pair<int,int>> q;
    q.push({startX,startY});
    visited[startX][startY] = true;
    dist[startX][startY] = 1;
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for (int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
            visited[nx][ny] = true;   
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    
    for (int i=0; i<maps.size(); i++){
        for (int j=0; j<maps[i].size(); j++){
            board[i][j] = maps[i][j];
        }
    }
    
    //내 진영 (1,1), 상대진영(n-1,m-1) 
    
    bfs(0,0);
    
    if (!visited[n-1][m-1]) answer = -1;
    else answer = dist[n-1][m-1];
    
    return answer;
}