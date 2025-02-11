#include <iostream>
#include <vector>

using namespace std;

// 0 = 빈칸, 6 = 벽, 1~5 = CCTV
// 세로 크기 N, 가로 크기 M
// CCTV 방향을 딱 정해서.
// 사각 지대(=CCTV가 감시 불가능한 부분)의 최소 크기를 출력.
// CCTV는 CCTV 통과 가능하다.

// curR : 세로(Row), curC : 가로(Column)

// 백트래킹 -> 현재 상태에서 가능한 모든 경우를 시도
// 유효하지 않는 경우 -> 더 깊이 탐색하지 않고 백트랙한다.
// 유효하면 계속 탐색한다.
// 최종 답 찾으면 종료.

int N, M;
int arr[9][9];
int minAnswer = 64;
vector<pair<int, int>> cctv;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void watch(int x, int y, int dir) {
    dir=dir%4;
    while (1) { // while 필요 이유는 전진해서 한 방향에서 cctv 가능한 범위 다 -1 처리하기 때문.
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny; // 하나 칸 처리하고 다음 전진 가능한 칸 처리 하는것임. (하나의 방향에 대해서)
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        if (arr[nx][ny] == 6) return;
        if (arr[nx][ny] != 0) continue;
        arr[nx][ny] = -1;
    }
}

void dfs (int idx) {
    if (idx == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 0) {
                    cnt++;
                }
            }
        }
        minAnswer = min(minAnswer, cnt);
        return;
    } // 각 cctv의 방향을 설정한 뒤 어떤 케이스에 대한 탐색을 마쳤을 때 돌아오는 조건문.

    int x = cctv[idx].first;
    int y = cctv[idx].second;
    // idx 확인 전에 x 진행 시 out of bounds 발생. 
    int tmp[9][9];

    for (int dir = 0; dir < 4; dir++) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                tmp[i][j] = arr[i][j];

        if (arr[x][y] == 1) {
            watch(x, y, dir);
        } else if (arr[x][y] == 2) {
            watch(x, y, dir);
            watch(x, y, dir+2);
        } else if (arr[x][y] == 3) {
            watch(x,y,dir);
            watch(x,y,dir+1);
        } else if (arr[x][y] == 4) {
            watch(x,y,dir);
            watch(x,y,dir+1);
            watch(x,y,dir+2);

        } else if (arr[x][y] == 5) {
            watch(x,y,dir);
            watch(x,y,dir+1);
            watch(x,y,dir+2);
            watch(x,y,dir+3);
        }
        dfs(idx + 1); // 하나의 cctv 좌표에 대해 방향 정한 후 다음 cctv 좌표에 대한 방향 정하기.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                arr[i][j] = tmp[i][j];
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 6) {
                cctv.push_back({i, j}); //cctv 좌표 저장
            }
        }
    }
    dfs(0);
    cout << minAnswer << "\n";
    return 0;
}