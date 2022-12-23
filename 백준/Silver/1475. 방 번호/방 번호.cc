#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string N;
	vector<int> vec(10);
	int max = vec[1];
	fill(vec.begin(), vec.end(), 0);
	cin >> N;
	for (int i = 0; i < N.length(); i++)
	{
		vec[N[i] - '0']++;
		if (vec[6] > vec[9] + 1)
		{
			vec[6]--;
			vec[9]++;
		}
		else if (vec[9] > vec[6] + 1)
		{
			vec[9]--;
			vec[6]++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (max < vec[i])
		{
			max = vec[i];
		}
	}
	cout << max << "\n";
}
