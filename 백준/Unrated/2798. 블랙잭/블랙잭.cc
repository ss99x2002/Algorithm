#include <iostream>
using namespace std;
int arr[100];
int main()
{
	int N, M;
	cin >> N >> M;
	int ans = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= M && ans < sum) {
					ans = sum;
				}
			}
		}
	}
	cout << ans;
}
