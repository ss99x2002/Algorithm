#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1)
	{
		bool flag = 0;
		string n;
		stack<char>stk;
		getline(cin, n);
		if (n == ".")
		{
			break;
		}
		else
		{
			for (int i = 0; i < n.length(); i++)
			{
				if (n[i] == '(')
				{
					stk.push(n[i]);
				}
				else if (n[i] == '[')
				{
					stk.push(n[i]);
				}
				else if (n[i] == ')')
				{
					if (!stk.empty() && stk.top() == '(')
					{
						stk.pop();
					}
					else {
						flag = 1;
						break;
					}
				}
				else if (n[i] == ']')
				{
					if (!stk.empty() && stk.top() == '[')
					{
						stk.pop();
					}
					else
					{
						flag = 1;
						break;
					}
				}
				else if (n[i] == '.')
				{
					break;
				}
			}
		}

		if (flag==0&&stk.empty())
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
}