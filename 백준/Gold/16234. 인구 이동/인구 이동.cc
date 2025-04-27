#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// n*n 크기의 땅 있고, 땅은 1*1로 나누어져 있다.
// 각 땅에 나라 하나씩 존재.
// A[r][c] = 나라에 사는 사람 수.

// 국경선을 공유하는 두 나라 인구 차이가 L명이상 R명 이하라면
// 두나라가 공유하는 국경선을 오늘 하루동안 연다.

// 연합을 이루고 있는 각 칸의 인구수는
// (연합의 인구수) / (연합을 이루고 있는 칸의 갯수) 가 된다.
// 각 나라 인구수가 주어졌을 때, 인구 이동이 며칠동안 발생하는지 구하기.

int n, l, r;

int board[51][51];
bool visited[51][51];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

vector<pair<int, int>> unions; // 연합 모음 벡터
vector<vector<pair<int, int>>> unionAll;

void initVisited() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
}

void dfs(int startX, int startY) {
    visited[startX][startY] = 1;
    unions.push_back({startX, startY});
    for (int dir = 0; dir < 4; dir++) {
        int nx = startX + dx[dir];
        int ny = startY + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (visited[nx][ny]) continue;
        if (abs(board[nx][ny] - board[startX][startY]) < l || abs(board[nx][ny] - board[startX][startY]) > r) continue;
        dfs(nx, ny);
    }
}

int days = 0;

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    while (1) {
        // 1.각 칸에 대해 dfs를 통해서. 인접한 국경 사이 오픈 여부를 확인한다.
        int flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    dfs(i, j);
                    if (unions.size() > 1) {
                        flag = true;
                        //연합 존재.
                        unionAll.push_back(unions);
                    }
                }
                unions.clear();
            }
        }

        if (!flag) {
            break;
        }

        // 인구 연합에 따른 인구 이동 로직
        for (int i = 0; i < unionAll.size(); i++) {
            int cnt = 0;
            int sum = 0;
            for (auto [x, y]: unionAll[i]) {
                cnt++;
                sum = sum + board[x][y];
            }
            int moveTotal;
            if (cnt != 0) moveTotal = sum / cnt;

            for (auto [x, y]: unionAll[i]) {
                board[x][y] = moveTotal;
            }
        }

        days++;
        initVisited();
        unionAll.clear();
    }

    cout << days;
}

