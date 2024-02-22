#include<vector>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int visited[101][101];

int solution(vector<vector<int> > maps)
{
    
    for (int i=0; i<101; i++){
        for (int j=0; j<101; j++){
            visited[i][j] = -1;
        }
    }
    int startX = 0;
    int startY = 0;
    
    int row = maps.size(); //행
    int col = maps[0].size(); //열
    
    q.push({startX,startY});
    visited[startX][startY] = 1;
    
    while(!q.empty()){
        pair<int,int> cur = q.front(); // 최상단의 값
        q.pop();
        for (int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= row || ny < 0 || ny >=col) continue;
            if (maps[nx][ny] == 0 || visited[nx][ny] > 0) continue;
            q.push({nx,ny});
            visited[nx][ny] = visited[cur.first][cur.second] + 1;
        }
    }
    return visited[row-1][col-1];
}