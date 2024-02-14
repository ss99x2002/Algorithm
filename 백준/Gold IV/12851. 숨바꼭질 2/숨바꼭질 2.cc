#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long N, K;

queue<pair<long long, long long>> q;
int arr[1000001];
int cnt[1000001];

int ans = 0;


void bfs() {
    while (!q.empty()) {
        int cur = q.front().first;
        int nowCnt = q.front().second;
        q.pop();
        for (int dir : {cur + 1, cur - 1, cur * 2}) {
            if (dir < 0 || dir >= 1000001) continue;
            if (arr[dir] != -1) {
                if (arr[dir] == nowCnt + 1) {
                    cnt[dir] = cnt[cur] + cnt[dir];
                }
            } //이미 방문했다면
            else {
                arr[dir] = nowCnt + 1;
                cnt[dir] = cnt[cur];
                q.push({ dir,arr[dir] });
            } //처음 방문 
        }
    }
} 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    fill(arr, arr + 1000001, -1);
    arr[N] = 0;
    cnt[N] = 1;
    q.push({ N,0 });
    bfs();
    cout << arr[K] << "\n" << cnt[K];
}

