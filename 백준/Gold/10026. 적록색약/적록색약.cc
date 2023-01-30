#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
char arr[101][101];
bool vis[101][101];
int N;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push({ i,j });
    vis[i][j] = 1;
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny] == 1 || arr[i][j] !=  arr[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({ nx,ny });
        }
    }
}

int area() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    int notg = area();
    for (int i = 0; i < N; i++)
        fill(vis[i], vis[i] + N, false);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'G')
                arr[i][j] = 'R';
        }
    }
    int g = area(); 
    cout << notg << " " << g;
}