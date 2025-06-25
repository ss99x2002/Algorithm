#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


int n,m;
int dist[1001][1001];
int board[1001][1001];
pair<int,int> start;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int startX, int startY){
    queue<pair<int,int>> s;
    dist[startX][startY] = 0;
    s.push({startX,startY});
    while(!s.empty()){
        auto [x,y] = s.front();
        s.pop();
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >=n || ny >=m) continue;
            if (board[nx][ny] == 0) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            s.push({nx,ny});
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> board[i][j];
            dist[i][j] = -1;
            if (board[i][j] == 2) {
                start = {i,j};
            }
        }
    }

    bfs(start.first, start.second);
    dist[start.first][start.second] = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j] == 0) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}