#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, cnt, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		cnt = 0;
		for (int i = 1; i <= M; i++)
		{
			if (M % i == 0 && M!=1)
			{
				cnt++;
			}
		}
		if (cnt == 2)
		{
			ans++;
		}
	}
	cout << ans;
}