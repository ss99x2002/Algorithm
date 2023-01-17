#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,N, cnt=0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cnt =0;
		int* arr = new int[N + 1];
		fill(arr, arr + N + 1, 0);
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == N) {
				cnt++;
			}
			for (int dir : {cur + 1, cur + 2, cur + 3}) {
				if (dir<0 || dir>N) continue;
				arr[dir] = arr[cur] + 1;
				q.push(dir);
			}
		}
		cout << cnt << "\n";
	}
}