#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first;
#define Y second;
int vis[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	fill(vis, vis + 1000001, -1);
	queue<int> q;
	q.push(1);
	vis[1] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == N) {
			cout << vis[cur];
			return 0;
		}
		for (int dir : {cur * 3, cur * 2, cur + 1}) {
			if (dir == N) {
				cout << vis[cur] + 1;
				return 0;
			}
			if ( dir>N || vis[dir]>=0) continue;
			vis[dir] = vis[cur] + 1;
			q.push({ dir });
		}
	}
	
}