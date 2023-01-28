#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K,ans=1,flag=0;
	cin >> N >> K;
	for (int i = N; i > K; i--) {
		ans = ans * i;
	}
	for (int i = N - K; i >= 1; i--) {
		ans = ans / i;
	}
	cout << ans;
}
