#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int t, n, m;
// n = A 원소 갯수, m = B 원소 갯수
vector<int> a;
vector<int> b;
int cnt = 0;

int input;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cnt = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }

        for (int i = 0; i < m; i++) {
            cin >> input;
            b.push_back(input);
        }

        // a,b vector에 담음
        // a > b인 쌍을 담아야 함.

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                if (a[i] > b[j]) {
                    cnt++;
                } else {
                    break;
                }
            }
        }

        cout << cnt << "\n";
        a.clear();
        b.clear();

    }
}