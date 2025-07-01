#include <iostream>
#include <queue>

using namespace std;

// 각 변의 길이가 1인 정육면체로 이루어져 있다.
// 인접한 6개의 칸 (동,서,남,북,상,하)로 이동할 수 있다.
// 출구를 통해서만 탈출 할 수 있다 -> 탈출할 수 있을까?

// L,R,C (l= 빌딩 층수, r,c = 한 층의 행 열)
// # = 막힌 칸, . = 비어있는 칸
// S = 시작 지점
// E = 출구
// L,R,C = 0으로 표현
// 시작과 출구는 항상 하나만 있다.

// 탈출 최단 시간 or 탈출 불가 하다면 출력

// 3차원 BFS 방향 (상하좌우앞뒤) 인접 칸 이동
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

// 인풋
int l, r, c;
char board[31][31][31];
int times[31][31][31];
pair<int, pair<int, int>> start;
pair<int, pair<int, int>> escape;
int ans = 0;

bool bfs() {
    queue<pair<int,pair<int,int>>> q;
    q.push(start);
    times[start.first][start.second.first][start.second.second] = 0;
    while(!q.empty()){
        auto [z,xy] = q.front();
        q.pop();
        for (int i=0; i<6; i++){
            int nx = dx[i] + xy.first;
            int ny = dy[i] + xy.second;
            int nz = dz[i] + z;

            if (nz < 0 || nx < 0 || ny < 0 ) continue;
            if (nz >= l || nx >= r || ny >= c) continue;
            if (times[nz][nx][ny] != -1) continue;
            if (board[nz][nx][ny] == 'E') {
                ans = times[z][xy.first][xy.second] + 1;
                return true;
            }
            if (board[nz][nx][ny] != '.') continue;

            times[nz][nx][ny] = times[z][xy.first][xy.second] +1;
            q.push({nz,{nx,ny}});
        }
    }
    return false;
}

void init() {
    ans = 0;
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            for (int k = 0; k < 31; k++) {
                board[i][j][k] = '0';
                times[i][j][k] = -1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) {
            break; //종료 조건
        }
        init();
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S') {
                        start = {i, {j, k}};
                    }
                }
            }
        }

        if(bfs()) {
            cout << "Escaped in " <<ans << " minute(s)." << "\n";
        }
        else {
            cout << "Trapped!" << "\n";
        }
    }
    return 0;
}