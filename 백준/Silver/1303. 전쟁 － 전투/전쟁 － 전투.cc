#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int board[101][101];
bool visit[101][101];

int dx[4] = { 1,0,-1,0 }; //아래 위
int dy[4] = { 0,1,0,-1 }; //오른 왼

int N, M;
char input;
int cnt = 0;

vector <int> white;
vector<int> blue;

queue<pair<int, int>> q;


void bfsWhite() {
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();   
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] != 1 || visit[nx][ny] == 1) continue;
            visit[nx][ny] = 1;
            cnt++;
            q.push({ nx,ny });
        }
    }
}

void bfsBlue() {
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] != 2 || visit[nx][ny] == 1) continue;
            visit[nx][ny] = 1;
            cnt++;
            q.push({ nx,ny });
        }
    }
}


void findWhite() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1 && visit[i][j] != 1) {
                visit[i][j] = 1;
                q.push({ i,j });
                bfsWhite();
                white.push_back(cnt + 1);
                cnt = 0;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < white.size(); i++) {
        sum = sum + (white[i] * white[i]);
    }
    cout << sum << " ";
}

void findBlue() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 2 && visit[i][j] != 1) {
                visit[i][j] = 1;
                q.push({ i,j });
                bfsBlue();
                blue.push_back(cnt + 1);
                cnt = 0;
            }
        }
    }
    int sumB = 0;
    for (int i = 0; i < blue.size(); i++) {
        sumB = sumB + (blue[i] * blue[i]);
    }
    cout << sumB << " ";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input;
            if (input == 'W') {
                board[i][j] = 1;
            }
            else if (input == 'B') {
                board[i][j] = 2;
            }
        }
    }

    findWhite();
    for (int i = 0; i < 101; i++) {
        fill(visit[i], visit[i]+101, 0);
    }
    findBlue();
}

