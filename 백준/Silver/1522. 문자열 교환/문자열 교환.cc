#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

string inputs;
int aCnt = 0;

int bCnt =0;
int minBcnt = 1001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> inputs;

    for (int i=0; i<inputs.size(); i++){
        if(inputs[i] == 'a') {
            aCnt ++;
        }
    }
    // 슬라이딩 윈도우 시작 -> 윈도우 사이즈는 aCnt

    for (int i=0; i<aCnt; i++){
        if (inputs[i] == 'b') {
            bCnt++;
        }
    }
    minBcnt = bCnt;

    for (int i=1; i<inputs.size(); i++){
        if (inputs[(i-1)% inputs.size()] == 'b') {
            bCnt --;
        }
        if (inputs[(i+aCnt-1)% inputs.size()] == 'b') {
            bCnt ++;
        }
        minBcnt = min(minBcnt,bCnt);
    }
    cout << minBcnt;
}