#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = { 1,0,-1,0 }; // 하상
int dy[4] = { 0,1,0,-1 }; // 우좌

int board[102][102]{};
int visited[102][102]{}; //거리를 담는 배열 
queue <pair<int, int>> q;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    int characterX2 = characterX * 2;
    int characterY2 = characterY * 2;
    int itemX2 = itemX * 2;
    int itemY2 = itemY * 2;

    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            visited[i][j] = -1;
        }
    }

    // X는 열 Y는 행  

    for (int i = 0; i < rectangle.size(); i++) {
        int startX = rectangle[i][0] * 2;
        int startY = rectangle[i][1] * 2;
        int endX = rectangle[i][2] * 2;
        int endY = rectangle[i][3] * 2;

        for (int i = startY; i <= endY; i++) {
            for (int j = startX; j <= endX; j++) {
                board[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < rectangle.size(); i++) {
        int startX = rectangle[i][0] * 2;
        int startY = rectangle[i][1] * 2;
        int endX = rectangle[i][2] * 2;
        int endY = rectangle[i][3] * 2;

        for (int i = startY + 1; i < endY; i++) {
            for (int j = startX + 1; j < endX; j++) {
                board[i][j] = 0;
            }
        }
    }

    q.push({ characterY2, characterX2 });
    visited[characterY2][characterX2] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= 102 || ny < 0 || ny >= 102) continue;
            if (board[nx][ny] == 0 || visited[nx][ny] >= 0 ) continue;
            q.push({ nx,ny });
            visited[nx][ny] = visited[cur.first][cur.second] + 1;
        }
    }
    answer = visited[itemY2][itemX2] / 2;
    return answer;
}