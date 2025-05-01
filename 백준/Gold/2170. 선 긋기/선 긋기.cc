#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 매우 큰 도화지에 자를 대고 선을 그으려고 한다.
// 선을 그을 때 자의 한 점에서 다른 한 점까지 긋게 된다.

// 선을 그을 때는 이미 선이 있는 위치에 겹쳐서 그릴 수 있다.
// 여러번 그은 곳과 그 곳의 차이를 구별할 수는 없다.

// 그려진 선들의 총 길이 프로그램 구하시오 -> 선이 여러번 그려진 곳은 한번만 계산한다.

int n;
int x, y;
vector<pair<int,int>> lines;

// 수행시간에서 1초에 처리가능한건 10^정도라 볼 수 있음.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x >> y;
        lines.push_back({x,y});
    }

    sort(lines.begin(), lines.end()); //오름차순 정렬.

    long long sum = 0;
    int curSt = lines[0].first;
    int curEd = lines[0].second;


    // 접근은 맞음 -> 이중 포문을 없애자. (이중 for 문시 시간 초과 발생)
    for (int i=1; i<n; i++) {
        int s = lines[i].first;
        int e = lines[i].second;

        if (s > curEd){
            sum = sum + abs(curSt-curEd);
            curSt = s;
            curEd = e;
        } // 더 커버리면, 아예 다른 병합 구간이 생기는 것임.
        else {
            curEd = max(curEd, e);
        }
    }

    sum = sum + abs(curSt-curEd); //마지막 처리 다 완료된 구간까지 더해주면 끝.
    cout << sum;
}
