#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int, int>> vec;
	int N, S, E;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> E;
		vec.push_back(make_pair(S, E));
	}
	sort(vec.begin(), vec.end(), compare);
	int ans = 0;
	int t = 0;
	for (int i = 0; i < N; i++) {
		if (t > vec[i].first) continue;
		ans++;
		t = vec[i].second;
	}
	cout << ans;

}
