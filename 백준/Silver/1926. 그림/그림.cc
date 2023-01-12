#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0 }; //상하좌우 네 방향
int dy[4] = { 0,1,0,-1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int cnt = 0, max = 0;
	cin >> n >> m;
	bool** arr = new bool* [n];
	bool** vis = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new bool[m];
		vis[i] = new bool[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			vis[i][j] = 0;
		}
	}
	for (int i=0; i<n; i++){
		for (int j = 0; j < m; j++)
		{
			int width = 0;
			if (arr[i][j] == 0 || vis[i][j]) continue;
			else
			{
				queue<pair<int, int>> q;
				vis[i][j] = 1;
				q.push({ i,j });
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop(); width++;
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || arr[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
				cnt++;
				if (max < width) max = width;
			}
		}
	}

	cout << cnt << "\n" << max;
}