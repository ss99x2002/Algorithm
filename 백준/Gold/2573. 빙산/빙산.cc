#include <iostream>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

// 빙산의 각 부분별 높이정보는 배열의 각 칸의 양의 정수로 저장된다.
// 빙산 이외의 바다에 해당하는 칸에는 0 저장된다.

// 빙산의 각 부분에 바다와 밀접한 칸에 있는 높이는 일년마다 붙어있는 0 칸의 갯수만큼 줄어든다.
// 각 칸에 지정된 높이는 0보다 더 줄어들지는 않는다.

// 빙산이 두 덩어리 이상으로 분리되는 최초의 년도를 구하는 프로그램
// 만약 전부 다 녹을 때 까지 두 덩어리 이상으로 분리되지 않으면 0 출력

int n, m;
int board[301][301];
bool visited[301][301];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void minusWater(int i, int j, int cnt) {
    if (board[i][j] - cnt > 0) {
        board[i][j] = board[i][j] - cnt;
    } else {
        board[i][j] = 0;
    }
}

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    visited[startX][startY] = true;
    q.push({startX, startY});
    while (!q.empty()) {
        pair<int, int> pq = q.front();
        q.pop();
        int x = pq.first;
        int y = pq.second;
        int waterCnt = 0;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 0) {
                waterCnt++;
                continue;
            }
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
        board[x][y] = max(0, board[x][y]-waterCnt);
    } // 한 덩어리에 대한 빙하 작용이 끝남.
    // 첫번째 이후로 분리가 생긴다면 ?
    // 한번 bfs돌고도 방문하지 않은 빙하가 존재해버림.
    // 이걸로 sperate를 판단하고 -> 년도를 출력하면 될듯 함.

}

void initVisited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
}

void check(int startX, int startY) {
    queue<pair<int, int>> q;
    visited[startX][startY] = true;
    q.push({startX, startY});
    while (!q.empty()) {
        pair<int, int> pq = q.front();
        q.pop();
        int x = pq.first;
        int y = pq.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == 0) continue;
            if (visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

void findSeparation() {
    int answer = 0;
    while (1) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 0 && !visited[i][j]) {
                    check(i, j);
                    cnt++;
                }
            }
        }

        if (cnt == 0) {
            // 전부 다 녹은거
            cout << 0 << "\n";
            return;
        } else if (cnt >= 2) {
            // 빙하 분리 발생
            cout << answer << "\n";
            return;
        }
        initVisited();

        // 빙하 분리가 일어나지 않으면 년도를 넘겨서 빙하 녹이기 시작
        answer++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 0 && !visited[i][j]) {
                    bfs(i, j); //녹이는 과정
                }
            }
        }
        initVisited();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    findSeparation();
}