#include <iostream>
#include <algorithm>


using namespace std;

// 로봇 청소기와 방의 상태가 주어질 때, 청소하는 영역의 개수 구하는 프로그램
// N*M 크기 직각 사각형애서, 각 칸은 빈칸 또는 벽
// 청소기가 바라보는 방향이 있다. (동,서,남,북)중 하나.

// 로봇 청소기 작동 방법
// 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸 청소
// 2.현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우, 바라보는 방향 유지한 채
// 한칸 후진할 수 있다면, 후진하고 1번으로 돌아 간다.
// 3.바라보는 방향의 뒤쪽 칸이 후진할 수 없다면, 작동 멈춘다.

// 1. 현재 주변 4칸 중 청소되지 않은 빈칸이 있는 경우,
// 2. 반시계 방향으로 90도 회전
// 3. 바라보는 방향 기준 앞쪽 칸이 청소되지 않은 빈칸 경우, 한칸 전진.

// 로봇 청소기 좌표 (r,c)
// 로봇 청소기 처음 바라보는 방향 d (0,1,2,3) 상,우,하,좌

int dx[4] = {-1,0,1,0}; // dx 유의해야 할 점.
// 위로 올라가는건 r 이 작아지는 것임. 따라서 -1이 상이다.
// 내려가는건 r이 커짐. 따라서 1이 하 이다.
int dy[4] = {0,1,0,-1};

// 로봇청소기가 작동을 시작한 후 작동 멈출때 까지 청소하는 칸의 갯수?

int r,c; //청소기 처음 좌표
int d; // 청소기 첫 방향
int n,m; // 방 크기

int room[51][51]; //0 빈칸, 1 벽, -1 청소완료
int visited[51][51];
int cnt = 0;


void dfs(int startX, int startY, int dir){
    visited[startX][startY] = true;
    if (room[startX][startY] == 0){
        room[startX][startY] = -1;
        cnt ++; //이미 청소 한 곳도 벽이 아니면 후진으로 갈 수 있으니까, 해당 조건문이 필요하다. 
    }

    // dir = 1 면  dir --;
    // dir = (dir+3)%4;
    for (int i=0; i<4; i++){
        dir  = (dir + 3 ) % 4;
        int nx = startX + dx[dir];
        int ny = startY + dy[dir];
        if (nx < 0 || ny < 0 || nx >=n || ny >=m ) continue;
        if (visited[nx][ny]) continue;
        if (room[nx][ny] != 0) continue;
        dfs(nx,ny,dir);
        return;
    }

    // 상하좌우 살폈는데 움직이지 못하는 경우.
       int backDir = (dir + 2) % 4; // 뒤로 가는 방향
       int nx = startX + dx[backDir];
       int ny = startY + dy[backDir];
        if (nx < 0 || ny < 0 || nx >=n || ny >=m ) return;
        if (room[nx][ny] == 1) return;
        dfs(nx,ny, dir);
}

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> room[i][j];
            // 1 :  벽, 0 : 빈 칸
        }
    }

    dfs(r,c,d);
    cout << cnt;
}