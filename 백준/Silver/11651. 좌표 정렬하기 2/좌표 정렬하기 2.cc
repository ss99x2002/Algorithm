#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, x, y;
	vector <pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back(pair<int, int>(y, x));
	}
	sort(v.begin(), v.end());
	for (long i = 0; i < v.size(); i++)
	{
		cout << v[i].second << " " << v[i].first << "\n";
	}
}
