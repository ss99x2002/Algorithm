#include <iostream>
#include <vector>
using namespace std;

bool arr[2000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n;
	vector <int> vec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	cin >> x;
	int cnt = 0;

	for (auto& data : vec)
	{
		if (x >= data && arr[x - data]) cnt++;
		arr[data] = true;
	}

	cout << cnt << "\n";
}