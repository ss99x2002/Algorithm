#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, D, K;
	vector<int> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		vec.push_back(D);
	}
	sort(vec.begin(), vec.end(), compare);

	cin >> M;
	while (M--) {
		cin >> K;
		cout << upper_bound(vec.begin(), vec.end(), K) - lower_bound(vec.begin(), vec.end(), K) << " ";
	}
}
