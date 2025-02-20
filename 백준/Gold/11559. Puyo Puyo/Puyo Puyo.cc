#include <iostream>
#include <queue>

using namespace std;

// 뿌요뿌요 룰
// 뿌요는 중력의 영향으로 아래 바닥 or 다른 뿌요가 나올때 까지 아래로 떨어짐.
// 뿌요를 놓고난 뒤, 뿌요가 4개이상 상하좌우 연결 시 연결된 같은 색 뿌요 사라짐
// 이 때 1 연쇄 시작

// 뿌요들 없어지고 위에 다른 뿌요 있으면, 차례로 아래로 내려온다.
// 아래 떨어지고나서 같은 색 뿌요들이 4개 이상 모이면 또 1연쇄 -> 1연쇄씩 늘어남.

// 터질 수 있는 뿌요가 여러그룹 있을 시 동시에 터지고, 여러브룹 터지더라도 한번의 연쇄가 추가.

// 상대 필드 주어질 때 연쇄가 몇번 연속으로 일어날지 게산.

int ans = 0;
char puyo[13][7];
vector<pair<int, int>> puyoColor;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[13][7];
vector<pair<int, int>> matchPuyo;

// 문제 나눠서 생각하기

// 1.컬러 뿌요 BFS 돌려서 상하좌우 4개 이상인 부분 확인 -> "."으로 변경
// 2. 제거된 뿌요 위에 다른 뿌요 있으면 뿌요 내려주기.

// puyo들 내려주기.
void drop() {
    for (int i = 0; i < 6; i++) {  // 각 열을 순회
        for (int j = 11; j >= 0; j--) {  // 아래에서 위로 탐색
            if (puyo[j][i] == '.') {  // 빈 공간 발견
                for (int k = j - 1; k >= 0; k--) {  // 위에서 뿌요 찾기
                    if (puyo[k][i] != '.') {  // 뿌요 발견 시 아래로 이동
                        puyo[j][i] = puyo[k][i];
                        puyo[k][i] = '.';
                        break;  // 한 칸만 이동 후 다시 탐색
                    }
                }
            }
        }
    }
}

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;

    int sf = start.first;
    int ss = start.second;
    char color = puyo[sf][ss];
    matchPuyo.push_back({sf, ss});
    q.push({sf, ss});
    visited[sf][ss]=1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if (puyo[nx][ny] == color && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
                matchPuyo.push_back({nx, ny});
            }
        }
    }
}

bool chain() {
    bool continues = false;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (!visited[i][j] && puyo[i][j] != '.') {
                bfs({i, j});
                if (matchPuyo.size() >= 4) {
                    continues = true;
                    for (auto matches: matchPuyo) {
                        puyo[matches.first][matches.second] = '.';
                    }
                }
                matchPuyo.clear();
            }
        }
    }
    return continues; //연쇄를 계속할지 여부
}

void initVisited() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            visited[i][j] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> puyo[i][j];
        }
    }

    while (chain()) {
        ans++;
        initVisited();
        drop();
    }

    cout << ans << "\n";
}