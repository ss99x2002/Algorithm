#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

int m, n;

// m * n 보드를 잘라서 8*8로 만들고 싶다.
// 체스판은 검은색, 흰색 번갈아 색칠해져 있어야 한다.
// 변을 공유하는 두개의 사각형은 다른색으로 칠해져 있어야 한다.

// 맨 왼쪽 위칸 흰색 경우 -1 / 맨 왼쪽 위칸 검은색 경우 -1

// 지민이는 8*8크기의 체스판으로 m*n을 잘라낸 후, 몇개의 정사각형을 다시 칠하려고 한다.
// 지민이가 다시 칠해야하는 정사각형의 최소 개수를 구하는 프로그램 작성.

int board[51][51];
// B :검은 = 1 , W : 흰색 =2

int minAnswer = 51 * 51;

int tempBoard[9][9];

void tempBoardClear() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tempBoard[i][j] = 0;
        }
    }
}

char inputs;


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> inputs;
            if (inputs == 'B'){
                board[i][j] = 1;
            }
            else {
                board[i][j] = 2;
            }
        }
    }

    for (int i = 0; i+7 < n; i++) {
        for (int j = 0; j+7 < m; j++) {
            int cnt1 = 0;
            int cnt2 = 0;
            for (int di = 0; di < 8; di++) {
                for (int dj = 0; dj < 8; dj++) {
                    int expect1 = ((di+dj) %2 ==0 ? 1 : 2);
                    int expect2 = ((di+dj) %2 ==0 ? 2 : 1);
                    if (board[i+di][j+dj] != expect1) cnt1 ++;
                    if (board[i+di][j+dj] != expect2) cnt2 ++;
                }
            }
            minAnswer = min(minAnswer, min(cnt1,cnt2));
        }
    }

    cout << minAnswer;
    return 0;
}
