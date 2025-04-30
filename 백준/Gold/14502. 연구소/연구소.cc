#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;
// 연구소 크기 N*M 직사각형 나타낼 수 있음.
// 빈칸, 벽으로 이루어지며 벽은 칸 하나를 차지한다.

//일부칸에는 바이러스 존재, 이 바이러스는 상하좌우 인접한 빈 칸으로 퍼져나갈 수 있다.
// 새로 세울 수 있는 벽은 3개, 꼭 3개를 세워야 한다.

// 0 = 빈칸, 1 = 벽, 2 = 바이러스

// 안전영역의 최댓값은?

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n,m;
int board[9][9];
int visited[9][9];
int visitedWalls[9][9];

vector<pair<int,int>> walls;
int maxAnswer = 0;


void initVisited(){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            visited[i][j] = false;
        }
    }
}

int calAnswer(){
    int cnt =0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j] == 0) cnt ++;
        }
    }
    return cnt;
}


void dfs(int startX, int startY){
    visited[startX][startY] = true;
    for (int dir =0; dir<4; dir++){
        int nx = startX + dx[dir];
        int ny = startY + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visited[nx][ny]) continue;
        if (board[nx][ny] == 1) continue;
        board[nx][ny] = 2;
        dfs(nx,ny);
    }
}

void backTracking(int startX, int startY, int cnt){
    if (cnt == 3) {
        int temp[9][9];
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                temp[i][j] = board[i][j];
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (board[i][j] == 2) {
                    dfs(i,j); //바이러스 퍼지기 전파
                }
            }
        }

        maxAnswer = max(maxAnswer,calAnswer());

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                board[i][j] = temp[i][j];
            }
        } //원복
        initVisited();
        return;
    }

    for (int i=startX; i<n; i++){
        for (int j = (i==startX ? startY+1 : 0); j<m; j++){
            if (board[i][j] == 0) {
                board[i][j] = 1;
                backTracking(i,j,cnt+1);
                board[i][j] = 0;
            }
        }
    }
}



int main() {
    cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j] == 0){
                board[i][j] = 1;
                backTracking(i,j,1);
                board[i][j] = 0;
            }
        }
    }

    cout << maxAnswer;

    // 1. 0인 부분에 벽을 세울 3개의 좌표 찾기
    // 2. 벽세우고, dfs로 바이러스 기점으로 퍼지는 완탐 시작.
    // 3. 안전지대 갯수 구해서 max 시 갱신하기.

}
