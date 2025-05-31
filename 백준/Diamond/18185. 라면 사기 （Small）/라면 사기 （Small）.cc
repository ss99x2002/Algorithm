#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100001];  // 문제 제한에 맞추어 충분히 크게 선언

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long answer = 0;

    // i번 공장(1-based)을 순회하면서, a[i]가 남아 있는 한
    for (int i = 1; i <= n; i++) {
        // i번에 라면이 남아 있으면 계속 처리
        while (a[i] > 0) {
            // 1) i, i+1, i+2 세 공장에서 각각 1개씩 사는 게 7원으로 가장 저렴
            if (i + 2 <= n && a[i + 1] > 0 && a[i + 2] > 0) {
                // 단, i+1 공장의 재고가 i+2 공장보다 많으면 “i,i+1 두 개 묶음(5원)”을 먼저 하는 편이 유리하다.
                if (a[i + 1] > a[i + 2]) {
                    // a[i+1]을 i+2에 맞추려고 하는 개수
                    int take = min(a[i], a[i + 1] - a[i + 2]);
                    a[i] -= take;
                    a[i + 1] -= take;
                    answer += (long long)take * 5;
                }
                    // 그렇지 않으면 (a[i+1] <= a[i+2]), 세 공장 묶음(7원)을 최대한 쓰자
                else {
                    int minV = min({a[i], a[i + 1], a[i + 2]});
                    a[i] -= minV;
                    a[i + 1] -= minV;
                    a[i + 2] -= minV;
                    answer += (long long)minV * 7;
                }
            }
                // 2) “3개 묶음”이 안 되는 상황이거나 꺼낸 후 다시 돌아왔을 때
                //    i+1 공장과 함께 사는 2개 묶음(5원)이 가능하다면
            else if (i + 1 <= n && a[i + 1] > 0) {
                int minV = min(a[i], a[i + 1]);
                a[i] -= minV;
                a[i + 1] -= minV;
                answer += (long long)minV * 5;
            }
                // 3) 그 외에는 남은 a[i]만큼 전부 단독 구매(3원) 처리
            else {
                answer += (long long)a[i] * 3;
                a[i] = 0;
            }
        }
    }

    cout << answer;
    return 0;
}