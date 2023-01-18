#include <iostream>
#include <queue>
using namespace std;

int D[301][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector <int> vec;
	int N, score;
	cin >> N;
	vec.push_back(0);
	for (int i = 1; i <=N; i++) {
		cin >> score;
		vec.push_back(score);
	}
	if (N == 1) {
		cout << vec[1];
		return 0;
	}
	D[1][2] = 0;
	D[1][1] = vec[1];
	D[2][1] = vec[2];
	D[2][2] = vec[2] + vec[1];
	for (int i = 3; i <= N; i++) {
		D[i][1] = max(D[i - 2][2], D[i - 2][1]) + vec[i];
		D[i][2] = D[i - 1][1] + vec[i];
	}
	cout << max(D[N][1], D[N][2]);

}