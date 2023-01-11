#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,flag;
	cin >> T;
	while (T--)
	{
		string VPS;
		stack<char>stk;
		flag = 0;
		cin >> VPS;
		for (int i = 0; i < VPS.length(); i++)
		{
			if (VPS[i] == '(')
			{
				stk.push(VPS[i]);
			}
			else if (VPS[i] == ')')
			{
				if (!stk.empty() && stk.top()=='(')
				{
					stk.pop();
				}
				else
				{
					stk.push(VPS[i]);
					flag = 1;
				}
			}
		}
		if (stk.empty() && flag==0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}