#include <iostream>
#include <cmath>
using namespace std;

// 이 대회는 n명이 참가하고, 토너먼트 형식으로 진행된다.
// n명의 참가자는 1번부터 N번까지 차례대로 배정받는다.
// 1-2, 2-3, n-1 - n 끼리 게임 진행한다.
// 각 게임에서 이긴 사람은 다음 라운드에 진출할 수 있다.

// 다음 라운드에 진출할 참가자 번호는 다시 1번부터 N/2번까지 차례대로 배정 받는다.
// 1-2번 겨루는 게임에서 2번 승리 시 -> 1번 부여 받고
// 3-4번 겨루는 게임에서 3번 승리 시 -> 다음 라운드 2번 부여 받는다.

// 처음 라운드에서 A번 가진 참가자는, 경쟁자로 생각하는 B참가자와 몇번째 라운드에서 만날지 궁금
// 게임 참가자 수 N, 참가자 번호 A, 경쟁자 번호 B가 있을 때. 몇번째 라운드에서 만나는지 return 함수
// 즉 두 참가자는 서로 붙기전까지 항상 이겨서 올라온다고 가정. 

int solution(int n, int a, int b)
{
    int answer = 0;
    long long round = 0;
    while(a != b){
        cout << " round = " << round << "\n";
        if (a%2 == 0) a = a/2; 
        else a = (a+1)/2;
        if (b%2 == 0) b = b/2;
        else b = (b+1)/2;
        round ++;
    }

    return round;
}