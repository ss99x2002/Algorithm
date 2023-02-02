#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, n;
    string clothes, kind;
    cin >> N;
    for (int i = 0; i < N; i++) {
        map<string, int>m;
        cin >> n;
        while (n--) {
            cin >> clothes >> kind;
            m[kind]++;
        }
        int ans = 1;
        for (auto it = m.begin(); it != m.end(); it++) {
            ans = ans * (it->second + 1);
        }
        cout << ans - 1 << "\n";
    }
}