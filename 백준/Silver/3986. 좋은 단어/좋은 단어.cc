#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, ans = 0;
	cin >> N;
	string ab;
	while (N--)
	{
		stack<char> stk;
		cin >> ab;
		for (int i = 0; i < ab.length(); i++)
		{
			if (stk.empty())
			{
				stk.push(ab[i]);
			}
			else {
				if (stk.top() == ab[i])
				{
					stk.pop();
				}
				else
				{
					stk.push(ab[i]);
				}
			}
		}
		if (stk.empty())
			ans++;
	}
	cout << ans;
}