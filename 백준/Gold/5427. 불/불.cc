#include <iostream>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

// 얼마나 빨리 빌딩을 탈출할 수 있는가?

// 테케
// 빌딩 너비와 높이 w, h
// h줄에 w개 문자 빌딩 지도 주어짐
//'.': 빈 공간
//'#': 벽
//'@': 상근이의 시작 위치
//'*': 불

// 빌딩 탈출에 가장 빠른 시간 출력
// 빌딩 탈출 없을 경우 "IMPOSSIBLE"

int t, w, h;
char board[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> peopleQ;
queue<pair<int, int>> fireQ;


void initVisited() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            visited[i][j] = false;
        }
    }
}

void initDist() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            dist[i][j] = -1;
        }
    }
}

void initQueue() {
    while (!peopleQ.empty()) {
        peopleQ.pop();
    }

    while (!fireQ.empty()) {
        fireQ.pop();
    }
}


void bfs() {
    dist[peopleQ.front().first][peopleQ.front().second] = 0;
    while (!peopleQ.empty()) {
        // 불 이동
        int size = fireQ.size();
        for (int i = 0; i < size; i++) {
            auto [fx, fy] = fireQ.front();
            fireQ.pop();
            for (int dir = 0; dir < 4; dir++) {
                int fnx = fx + dx[dir];
                int fny = fy + dy[dir];

                if (visited[fnx][fny]) continue;
                if (fnx < 0 || fny < 0 || fnx >= h || fny >= w) continue;
                if (board[fnx][fny] != '.' && board[fnx][fny] != '@') continue;
                board[fnx][fny] = '*';
                visited[fnx][fny] = true;
                fireQ.push({fnx, fny});
            }
        }

        // 사람 이동
        int pSize = peopleQ.size();
        for (int i = 0; i < pSize; i++) {
            auto [x, y] = peopleQ.front();
            peopleQ.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                    cout << dist[x][y] + 1 << "\n";
                    return;
                }
                if (dist[nx][ny] != -1) continue;
                if (board[nx][ny] == '#' || board[nx][ny] == '*') continue;
                peopleQ.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}


int main() {
    cin >> t;
    while (t--) {
        cin >> w >> h;
        initVisited();
        initDist();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
                if (board[i][j] == '@') {
                    peopleQ.push({i, j});
                }
                if (board[i][j] == '*') {
                    fireQ.push({i, j});
                }
            }
        }
        //탈출 경우 찾기
        bfs(); //불과 사람이 동시에 bfs되도록 즉 sync를 맞추어서 돌려야한다.
        initQueue();
    }
}