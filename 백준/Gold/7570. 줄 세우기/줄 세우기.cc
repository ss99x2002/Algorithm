#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

// 모든 어린이들에게 입학할 때 주어진 번호고, 옷에 번호표 달고 있다.
// 선생님은 다음과 같은 방법으로 줄 세울거다.

// 1. 줄 서있는 어린이 중 한명을 선택해 제일 앞이나 뒤로 보낸다.
// 위 방법으로 빈자리 생길 경우, 빈 자리의 뒤에 있는 어린이가 한걸음씩
// 앞으로 와서 빈자리 메꾼다.

// ex) 5 2 4 1 3
// 1. 1번 제일 앞으로 보낸다. (1,5,2,4,3)
// 2. 4번 제일 뒤로 보낸다. (1,5,2,3,4)
// 3. 5번 제일 뒤로 보낸다. (1,2,3,4,5)

// 번호순서대로 줄을 세울 때, 앞이나 뒤로 보내는 어린이의 수 최솟값 찾기.

// n = 어린이 수,  어린이 번호 차례대로 입력

int n,num;
int  pos[1000001];

// dp와 LIS (최대 증가 부분 수열)
// LIS -> dp로 풀었던 기억.

int main() {
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> num;
        pos[num] = i; // 현재 Num이 서 있는, 위치의 숫자를 저장.
    }

    int best = 1, cur = 1; //1~n 번까지 번호순으로 보면서,
    // pos[i] > pos[i-1] 이 이어지는 구간의 최대 길이를 구한다.

    for (int i=2; i<=n; i++){
        if (pos[i] > pos[i-1]){
            cur++; // 연속되어 움직일 필요가 없는 아이들의 숫자.
        }
        else {
            // 연속이 끊기는 경우
            best = max(best,cur);  //연속되어 움직일 필요가 없는 숫자와,
            cur=1;
        }
    }

    best = max(best,cur);
    cout << (n-best) << "\n";
    //전체 n명 중에 안움직여도 되는 연속 구간 크기를 빼주면 -> 움직이는 아이들 최소 이동 횟수 나옴.
    return 0;
}
