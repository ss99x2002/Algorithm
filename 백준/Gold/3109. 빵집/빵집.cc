#include <iostream>
#include <algorithm>

using namespace std;

// 빵집이 있는 곳은 R*C격자로 표현할 수 있다.
// 첫번째 열은 근처 빵집의 가스관이고, 마지막 열은 원웅이의 빵집이다.
// 가스관과 빵집을 연결하는 파이프를 설치하려고 한다.
// 빵집과 가스관 사이에는 건물이 있을 수도 있다.건물이 있는 경우 파이프 놓을 수 없다.


// 가스관과 빵집을 연결하는 모든 파이프라인은 첫번째 열에서 시작해야하고, 마지막 열에서 끝나야 한다.
// 각 칸은 오, 오른쪽 위 대각선, 오른쪽 아래 대각선으로 연결할 수 있고, 각 칸 중심끼리 연결한다.

// 원웅이는 가스 최대한 많이 훔치려한다.
// 파이프라인 경로는 서로 겹칠 수 없고, 접할 수 없다. 각 칸을 지나는 파이프는 1개어야 한다.
// 원웅이가 설치할 수 있는 가스관과 빵집을 연결하는 파이프라인의 초대 갯수 구하기.

int r, c;
int board[10001][501]; // 1: 빈칸, -1: 도달 불가능 칸
bool visited[10001][501];
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};
char inputs;

int maxAnswer = 0;

bool dfs(int curX, int curY) {
    visited[curX][curY] = true;
    if (curY == c - 1) {
        return true;
    }
    for (int dir = 0; dir < 3; dir++) {
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (visited[nx][ny]) continue;
        if (board[nx][ny] != 1) continue;
        if(dfs(nx,ny)) return true;
    }
    return false;
}

void backTracking(int curX, int curY) {
    if (dfs(curX, curY)) maxAnswer++;
}


int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> inputs;
            if (inputs == '.') {
                board[i][j] = 1;
            } else if (inputs == 'x')
                board[i][j] = -1;
        }
    }


    for (int i = 0; i < r; i++) {
        if (board[i][0] == 1) {
            backTracking(i, 0);
        }
    }

    cout << maxAnswer;

    return 0;
}