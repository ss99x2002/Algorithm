#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

// n*m 행렬 맵 존재 0 : 이동가능, 1 : 이동 불가 벽
// (1,1) -> (n,m) 까지 이동할 때 최단경로로 이동
// 시작하는 칸과 끝나는 칸 포함 세기 (시작점부터 1)
// 만약 이동 도중 경로가 짧아진다면, 한개의 벽 부수고 이동 가능

// 한 칸에서 이동할 수 있는건 상하좌우 인접칸
// 최단경로 구하기 -> BFS

//맵 주어질때 최단경로는?

int n,m;
int board[1001][1001]; //현재까지 거리 왔을 때, 부순건지 안부순건지 확인하기 위함.
int dist[1001][1001][2];
int visited[1001][1001][2];

int dx[4] = {0, 1, 0 ,-1};
int dy[4] = {1,0,-1,0};

int bfs(){
    queue<tuple<int,int,int>> q;
    dist[0][0][0] = 1;
    visited[0][0][0] = true;
    q.emplace(0,0,0);
    while(!q.empty()){
        auto [x,y,broken] = q.front();
        q.pop();

        if (x == n-1 && y == m-1){
            return dist[x][y][broken]; // 도착지에 도달했다면 최소값 바로 반환
        }

        for (int dir = 0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >=n || ny >=m) continue;
            if (board[nx][ny] == 0 && !visited[nx][ny][broken]) {
                visited[nx][ny][broken] = true;
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.emplace(nx,ny,broken);
            }

            else if (board[nx][ny] == 1 && broken == 0 && !visited[nx][ny][broken]) {
                visited[nx][ny][1] = true;
                dist[nx][ny][1] = dist[x][y][0] + 1;
                q.emplace(nx,ny,1);
            }
        }
    }
    return -1;
}

string input;

int main() {
    ios::sync_with_stdio(0); // 이거 넣어주도록 하자..
    cin.tie(NULL);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        cin >> input;
        for (int j=0; j<m; j++){
            board[i][j] = (int)(input[j])-'0';
        }
    }

   cout << bfs() << "\n";
}
