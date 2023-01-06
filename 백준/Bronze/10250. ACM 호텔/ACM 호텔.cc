#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, H, W, N;
	int h = 1, w = 1;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> H >> W >> N;
		h = 1, w = 1;
		for (int i = 1; i <= N; i++)
		{
			if (i == N)
			{
				if (w < 10)
				{
					cout << h <<0<< w << "\n";
					break;
				}
				else
				{
					cout << h  << w << "\n";
					break;
				}
			}
			h++;
			if (h > H)
			{
				h = 1;
				w++;
			}
		}
	}
}