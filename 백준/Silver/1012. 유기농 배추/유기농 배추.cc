#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main()
{
	int T,M, N,k,X,Y,cnt=0;
	cin >> T;
	while (T--) {
		cin >> M >> N >> k;
		bool arr[51][51] = { 0 };
		bool vis[51][51] = { 0 };
		queue<pair<int, int>> start;
		queue<pair<int, int>> q;
		cnt = 0;
		for (int i = 0; i < k; i++) {
			cin >> X >> Y;
			arr[X][Y] = 1;
			start.push(make_pair(X, Y));
		}

		while (!start.empty()){
			if (vis[start.front().first][start.front().second] == 1) {
				start.pop();
				continue;
			}
			q.push(start.front());
			start.pop();
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx >= M || nx < 0 || ny >= N || ny < 0) continue;
					if (arr[nx][ny] < 1 || vis[nx][ny] >= 1) continue;
					vis[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
			cnt++;
		}
		cout << cnt << "\n";
	}
}
