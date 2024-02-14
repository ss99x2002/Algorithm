#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long A, B;
queue<pair<long long, long long>> q;

long long bfs() {
    while (!q.empty()) {
        long long cur = q.front().first;
        long long nowCnt = q.front().second;
        q.pop();
        if (cur == B) {
            return nowCnt;
        }
        for (long long dir : {cur * 2, cur * 10 + 1}) {
            if (dir < 0 || dir > B) continue;
            q.push({ dir, nowCnt+1 });
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B;
    q.push({ A,1 });
    cout << bfs();
}
