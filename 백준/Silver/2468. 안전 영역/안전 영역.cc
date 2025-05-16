#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

int n;
int board[101][101];
// 장마철 물에 잠기지 않는 안전영역 최대 개수 출력

// 장마철 물에 잠기는 cm 최대
int minH = 101*101;
int maxAnswer = 0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool visited[101][101] = {0};

void initVisited(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
}

void bfs(int startX, int startY, int h){
    queue<pair<int,int>> q;
    q.push({startX,startY});
    visited[startX][startY] = true;
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] <= h) continue;
            if (visited[nx][ny]) continue;
            q.push({nx,ny});
            visited[nx][ny] = true;
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> board[i][j];
            if (board[i][j] <= minH){
                minH = board[i][j];
            }
        }
    }

    for (int h=minH-1; h<=100; h++){
        initVisited();
        int cnt =0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (board[i][j] > h && !visited[i][j]){
                    bfs(i,j,h);
                    cnt ++;
                }
            }
        }
        maxAnswer = max(maxAnswer,cnt);
    }

    cout << maxAnswer;
    return 0;
}
