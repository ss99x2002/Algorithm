#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

// 틱택토 게임은 두명의 사람이 번갈아가며 말을 놓는 게임
// 3*3 격자판 게임판에서
// 반드시 첫번째 사람이 X, 두번째 사람이 O
// 가로,세로,대각선 방향 3칸 잇는데 성공하면 게임 즉시 끝남
// 게임판이 가득 차도 게임 끝난다.

// 게임 상태 주어질 때, 틱택토 게임에서 발생할 수 있는 최종 상태인지 판별

// X,O,.은 빈칸.
// end가 주어질 때 입력의 마지막이 됨.

string input;

// 구현 순서
// 1. 입력 문자열 -> 3*3 보드로 바꾼다.
// 2. X,0,.갯수 센다.
// 3. isWin(board,'x') / isWin(board,'o') 로 빙고 여부 체크한다.
// 4. x 이길 경우, o보다 갯수 1개 더 많아야 함.
// 5. o 이길 경우, x와 갯수 같아야 함.
// 6. 둘다 이길경우 -> invalid함.
// 7. 아무도 안 이길 경우 -> 보드가 꽉 차 있어야만 valid // 왜냐면 틱택토 최종 상태인지를 묻는 문제이기 때문

// 즉. 최종 적으로 게임이 끝났을 때 발생할 수 있는 경우인지 확인하는 것임
// 게임 끝나는 조건은
// 누군가 3개 연속 승리 or 보드가 다 찬 경우임.

char board[3][3];

bool isWin(char player){
    for (int i=0; i<3; i++){
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

int countPlayer(char player){
    int cnt =0;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j] == player){
                cnt ++;
            }
        }
    }
    return cnt;
}

int main(){
    while(1){
        int cnt = 0;
        cin >> input;
        if (input == "end"){
            break;
        }
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                 board[i][j] = input[(3*i)+j];
             }
        }
        if (isWin('X') && !isWin('O')){
            if (countPlayer('X') == countPlayer('O') + 1) {
                cout << "valid" << "\n";
            }
            else {
                cout << "invalid" << "\n";
            }
        }
        else if (!isWin('X') && isWin('O')){
            if(countPlayer('X') == countPlayer('O')) {
                cout << "valid" << "\n";
            }
            else {
                cout << "invalid" << "\n";
            }
        }

        else if (isWin('X') && isWin('O')){
            cout << "invalid" << "\n";
        }

        else {
            if (countPlayer('.') == 0 && (countPlayer('X') > countPlayer('O'))){
                cout << "valid" << "\n";
            } else {
                cout << "invalid" << "\n";
            }
        }
    }
}