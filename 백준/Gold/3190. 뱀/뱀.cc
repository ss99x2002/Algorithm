#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

// Dummy라는 도스 게임 있음.
// 사과를 먹으면 뱀의 길이가 늘어난다.
// 뱀은 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.

// N*N 정사각 보드 위에 사과가 놓여져 있음.
// 상하좌우 끝에는 벽이 있다.
// 뱀은 0,0에 위치하고 길이는 1이다.

// 처음에는 오른쪽을 향한다.
// 매 초마다 이동하는데 다음과 같은 규칙

// 1. 뱀은 몸 길이를 늘려 머리를 다음칸에 위치시킨다.
// 2.  만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
// 3. 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과는 없어지고, 꼬리는 움직이지 않는다.
// 4. 만약 이동한 칸에 사과가 없다면, 몸 길이를 줄여 꼬리가 위치한 칸을 비워준다.
// -> 즉 몸 길이는 변하지 않는다.

// 이 게임이 몇초에 끝나는지 계산하자.

int n,k;
int k1,k2;
int board[101][101];
// 1based 배열로 만들것.
// -1은 보드 칸 (사과는 없는 칸)
//  0은 보드 칸이 아닌 부분
//  1은 보드 내 사과 있는 칸

int l; //뱀의 방향 변환 횟수
int x;
char c; //x초가 끝난 후 왼쪽 또는 오른쪽으로 90도 회전 함.

vector<pair<int,char>> moves;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


int main() {
    cin >> n; //보드
    cin >> k; // 사과 갯수

    deque<pair<int,int>> q; //뱀의 머리와 꼬리 위치를 저장.
    // 머리랑 꼬리 둘다 변동 가능성 있으므로, 위 아래에서 뺼 수 있도록 deque (덱) 사용

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] = -1;
        }
    }


    for (int i = 0; i < k; i++) {
        cin >> k1 >> k2; // 사과 위치 좌표.
        board[k1][k2] = 1;
    }


    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> x >> c;
        moves.push_back({x, c});
    }

    int time=0;
    int dirIdx = 0;
    int moveIdx = 0;

    q.push_front({1,1});

    while(1){
        time ++;
        int nx = q.front().first + dx[dirIdx];
        int ny = q.front().second + dy[dirIdx];

        if (board[nx][ny] == 0 || find(q.begin(), q.end(), make_pair(nx,ny)) != q.end()){
            break;
        }

        q.push_front({nx,ny});

        if (board[nx][ny] == -1){
            q.pop_back();
        } else if (board[nx][ny] == 1){
            board[nx][ny] = -1;
        }

        if (time == moves[moveIdx].first && moveIdx < moves.size()) {
            if (moves[moveIdx].second == 'D'){
                dirIdx = (dirIdx + 1)%4;
            } else  {
                dirIdx = (dirIdx + 3 ) %4;
            }
            moveIdx ++;
        }

    }

    cout << time;
}

