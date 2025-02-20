#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 5*5 정사각형 격자 자리 (25명)
// 7명의 자리는 가로, 세로로 반드시 인접
// 이다솜파 학생들로만 구성될 필요 x
// 하지만 이다솜파 적어도 4명이상 필요.

// 자리 배치도 중 7공주 결성 가능한 모든 경우의 수는?

// 중요한 사실은 칠공주의 배치가 어떻게되든. 동일한 애들끼리 다른 자리에 앉은 경우는 같은 경우로 생각해야 함.
// 따라서 조합도 포함되어있는 문제다. -> 간과한 부분.

char seat[6][6];
int ans = 0;
vector<pair<int, int>> selected;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};


bool bfsSeat(vector<pair<int, int>> selected) {
    queue<pair<int, int>> q;
    bool visited[6][6] = {false};

    q.push(selected[0]);
    visited[selected[0].first][selected[0].second] = true;

    int cnt = 1;
    int cntS = 0;
    if (seat[selected[0].first][selected[0].second] == 'S') cntS = 1;

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            for (auto &p: selected) {
                if (nx == p.first && ny == p.second && !visited[nx][ny]) {
                    if (seat[nx][ny] == 'S') cntS ++;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt == 7 && cntS >=4 ;
}

void comb(int start, int cnt) { //25 자리 중 7개 뽑는 조합 함수
    if (cnt == 7) {
        if (bfsSeat(selected)) {
            ans++;
        }
        return;
    }

    for (int i = start; i < 25; i++) {
        int x = i / 5;
        int y = i % 5;

        selected.push_back({x, y});
        comb(i + 1, cnt + 1); // 또 다른 선택의 시작 지점은 뽑은 애 다음부터 해도되는 것..
        selected.pop_back(); // 백트래킹
    }
}


int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> seat[i][j];
        }
    }
    comb(0,0);
    cout << ans << "\n";
}