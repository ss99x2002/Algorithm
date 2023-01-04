#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, A;
int ans[1000001];
int a[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int>stk;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		a[i] = A;
	}

	for (int i = N - 1; i >= 0; i--)
	{

		while (!stk.empty() && stk.top() <= a[i])
		{
			stk.pop();
		}
		if (stk.empty())
		{
			ans[i] = -1;
		}
		else
		{
			ans[i] = stk.top();
		}
		stk.push(a[i]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
}