#include <iostream>
#include <algorithm>

using namespace std;

// n*n 체스판에 퀸 n개를 서로 공격하지 못하는 위치에 놓는 경우의 수 문제.
// 퀸은 체스판 위에서 상하좌우, 대각선으로 공격할 수 있는 기물
// n=14 이하.

// 상하좌우 탐색 -> dx,dy
// 대각선 탐색 -> (상,오) / (상,왼) / (하,오) / (하,왼) 각각이 동일한 숫자로 한번에 이동하면 대각선 이동 가능.

int n;
// n*n에서 퀸 n개를 서로 공격할 수 없게 놓는 문제.

// 굳이 탐색 다 하지 않아도 됨.
// 퀸은 한 행에 하나만 둘 수 있음
// 하나의 행에 둔 열을 저장. 열도 동일하면 안됨.
// 대각선은 비교하는 두 좌표 거리 x,y 동일하면 안됨


// (1,1) arr[1]=1; arr[3] = 3;
// (1,2) arr[1]=2; arr[2] = 3; arr[3] = 4;

int ans = 0;
int board[16];

int watchQueen(int row){
    for (int i=0; i<row; i++){
        if (board[row] == board[i] || row-i == abs(board[row]-board[i])){
            return -1;
        }
    }
    return 1;
}

void checkQueen(int qNum) {
    if (qNum == n) {
        ans++; // qNum은 행임.
        return;
    }

    for (int i=0; i<n; i++){
        board[qNum] = i; // qNum 행 i열에 queen 둠.
        if (watchQueen(qNum) == 1){
            checkQueen(qNum+1);
        }
    }
}


int main() {
    cin >> n;
    checkQueen(0);
    cout << ans;
}