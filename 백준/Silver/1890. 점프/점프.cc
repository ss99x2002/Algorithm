#include <iostream>
#include <stack>

using namespace std;

int n;
// 게임의 목표 : 가장 왼쪽 위 칸에서, 가장 오른쪽 아래칸으로 규칙에 맞게 점프

// 각 칸의 적혀있는 수 -> 현재 칸에서 갈 수 있는 거리 의미
// 반드시 오른쪽 or 아래쪽만 이동
// 0은 더이상 진행 막는 종착점
// 현재 칸에서 적혀있는 수만큼 오른 or 아래만
// 한번 점프 할 때 방향 바꾸면 안됨

// 가장 왼쪽 -> 가장 오른쪽 아래칸까지 이동 경로갯수

// ?? DFS 가능 or dp인듯
// DFS 안됨 -> visited없는 그냥 경로 갯수라서 지수 단위 -> 시간초과 발생
// 메모리제이션 활용 dp로 풀어야한다.


int board[101][101];
long long dp[101][101];
long long ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) continue;
            if (i + board[i][j] < n) {
                dp[i + board[i][j]][j] = dp[i + board[i][j]][j] + dp[i][j];
            }

            if (j + board[i][j] < n) {
                dp[i][j + board[i][j]] = dp[i][j + board[i][j]] + dp[i][j];
            }
        }
    }

    cout << dp[n - 1][n - 1] << "\n";
}