#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int box[1002][1002];
int vis[1002][1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M, N;
	bool flag = 0;
	cin >> M >> N;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i,j });
			}
			if (box[i][j] == 0) {
				vis[i][j] = -1;
				flag = 1;
			}
		}
	}

	if (!flag) {
		cout << 0;
		return 0;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (vis[nx][ny]>=0) continue;
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}
	int maxV = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			if (vis[i][j]==-1)
			{
				cout << -1;
				return 0;
			}
			maxV = max(maxV, vis[i][j]);
		}
	}
	cout << maxV;
}