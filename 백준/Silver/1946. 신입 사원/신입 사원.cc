#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    int P, M; // 서류, 면접

    cin >> T;
    for (int i = 0; i < T; i++) {
        int ans = 1;
        cin >> N;
        vector <pair<int, int>> v;
        for (int j = 0; j < N; j++) {
            cin >> P >> M;
            v.push_back(make_pair(P, M));
        }
        sort(v.begin(), v.end()); 

        int top = v.front().second;
        for (int i = 1; i < N; i++) {
            if (top > v[i].second) {
                ans++;
                top = v[i].second;
            }
        }

        cout << ans << "\n";
    }

}
