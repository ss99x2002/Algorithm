#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	int all = 0;
	string S1, S2;
	cin >> S1;
	cin >> S2;
	vector <int> V1(26);
	vector <int> V2(26);
	fill(V1.begin(), V1.end(), 0);
	fill(V2.begin(), V2.end(), 0);
	for (int i = 0; i < S1.length(); i++)
	{
		V1[S1[i] - 'a']++;
	}
	for (int i = 0; i < S2.length(); i++)
	{
		V2[S2[i] - 'a']++;
	}
		
	for (int i = 0; i < V1.size(); i++)
	{
		if (V1[i] != V2[i])
			{
				if (V1[i] > V2[i])
				{
					if (V1[i] != 0)
					{
						cnt = cnt+V1[i] - V2[i];
						V1[i] = V2[i];
					}
				}
				else
				{
					if (V2[i] != 0)
					{
						cnt =cnt+ (V2[i] - V1[i]);
						V1[i] = V2[i];
					}
				}
			}
	}
	cout << cnt << "\n";
}