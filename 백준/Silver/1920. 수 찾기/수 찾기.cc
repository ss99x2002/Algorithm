#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int D[301][3];
bool compare(int a, int b) {
	return a < b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector <int> vec;
	vector <int> vec2;
	int N, M, A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		vec.push_back(A);
	}
	sort(vec.begin(), vec.end(), compare);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> A;
		vec2.push_back(A);
	}
	for (int i = 0; i < M; i++) {
		int low = 0;
		int flag = 0;
		int hight = vec.size() - 1;
		int mid;
		while (low <= hight) {
			mid = (low + hight) / 2;

			if (vec[mid] == vec2[i]) {
				cout << "1\n";
				flag = 1;
				break;
			}
			else if (vec[mid] > vec2[i]) {
				hight = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		if (flag == 0) {
			cout << "0\n";
		}
	}
}