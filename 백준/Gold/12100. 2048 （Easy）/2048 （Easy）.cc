#include <iostream>
#include <vector>

using namespace std;

int n;
int board[21][21];
int board2[21][21];
int answer=0;

void rotate() { //90도 rotate 함수
    int tmp[21][21];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            tmp[i][j] = board2[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            board2[i][j] = tmp[n-1-j][i];
        }
    }
}


void left(int dir){
    while(dir--) rotate(); // 상,하,좌,우 에 따라서 dir다름. 상 -> 270도 회전 필요 따라서 while
    for (int i=0; i<n; i++) {
        int tilted[21] = {};
        int idx = 0;
        for (int j=0; j<n; j++) {
            if (board2[i][j] == 0) continue;
            if (tilted[idx]== 0) {
                tilted[idx] = board2[i][j];
            }
            else if (tilted[idx] == board2[i][j]) {
                tilted[idx++] = tilted[idx]*2;
            }
            else
                tilted[++idx] = board2[i][j];
        }
        for (int j=0; j<n; j++) board2[i][j] = tilted[j]; // 왼쪽으로 옮긴 다음 이를 복사.
    }
}

void dfs(int depth) {
    if (depth == 5) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                answer = max(answer, board2[i][j]);
        return;
    }

    int backup[21][21];


    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            backup[i][j] = board2[i][j];
        }
    }

    for (int dir=0; dir<4; dir++) {
        // 0 왼, 1 아래, 2 우, 3 상
        left(dir);
        dfs(depth +1);

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                board2[i][j] = backup[i][j];
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
          board2[i][j] = board[i][j];
        }
    }

    dfs(0);
    cout << answer;
    return 0;
}