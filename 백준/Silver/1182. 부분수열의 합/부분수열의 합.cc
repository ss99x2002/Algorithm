#include <iostream>
#include <algorithm>

using namespace std;

int num[21];
int visited[21];
int cnt = 0;
int n,s;
// n = 수열 정수 개수, s = 합 나와야 하는 정수

void backTracking(int idx, int sum, bool selected){
    if (idx == n) {
        if (sum == s && selected){
            cnt ++;
        }
        return;
    }

    backTracking(idx + 1, sum,selected);
    backTracking(idx + 1, sum+num[idx],true);
}

int main() {
    cin >> n >> s;
    for (int i=0; i<n; i++){
        cin >> num[i];
    }
    backTracking(0,0,false);
    cout << cnt;
}