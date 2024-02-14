#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int board[101][101];
bool visit[101][101];

int N, M, K;
int r, c;

int ans = 0;
int cnt = 0;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > N || ny < 0 || ny > M) continue;
        if (board[nx][ny] != 1 || visit[nx][ny] == 1) continue;
        visit[nx][ny] = 1;
        cnt++;
        dfs(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        board[r][c] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] != 0 && visit[i][j] != 1) {
                visit[i][j] = 1;
                dfs(i, j);
                if (ans < cnt) {
                    ans = cnt;
                }
                cnt = 0;
            }
        }
    }

    cout << ans+1;
   
}

