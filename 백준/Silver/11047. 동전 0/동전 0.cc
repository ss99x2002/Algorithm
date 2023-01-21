#include <iostream>
using namespace std;

int arr[15];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		ans = ans + (k / arr[i]);
		k = k % arr[i];
	}
	cout << ans;
}
