#include <iostream>
#include <stack>

using namespace std;

int N,h;
int ans[500000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long ans = 0;

	stack<pair<int, int>> stk;

	cin >> N;
	
	while (N--) {
		cin >> h;
		int cnt = 1;
		while (!stk.empty() && stk.top().first <= h)
		{
			ans = ans + stk.top().second;
			if (stk.top().first == h)
				cnt = cnt + stk.top().second;
			stk.pop();
		}
		if (!stk.empty())
		{
			ans++;
		}
		stk.push({ h,cnt });
	}
	cout << ans;
}