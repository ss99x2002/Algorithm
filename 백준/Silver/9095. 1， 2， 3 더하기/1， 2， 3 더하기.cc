#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int* arr = new int[N + 1];
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;
		for (int i = 4; i <= N; i++) {
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}
		cout << arr[N] << "\n";
	}
}