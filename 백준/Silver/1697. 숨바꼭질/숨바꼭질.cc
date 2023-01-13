#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dist[100002];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	fill(dist, dist+100001, -1);
	dist[N] = 0;
	queue<int>q;
	q.push(N);
	while (dist[K]==-1)
	{
		int cur = q.front();
		q.pop();
		for (int dir : {cur-1,cur+1,2*cur})
		{
			if (dir < 0 ||dir >100000) continue;
			if (dist[dir]!=-1) continue;
			dist[dir] = dist[cur] + 1;
			q.push(dir);
		}
	}
	cout << dist[K];
}