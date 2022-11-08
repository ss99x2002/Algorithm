#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int main()
{
	int N,order;
	string M;
	cin >> N;
	stack<int> stack;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		if (M == "push")
		{
			cin >> order;
			stack.push(order);
		}
		else if (M == "pop")
		{
			if (stack.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << stack.top() << "\n";
				stack.pop();
			}
		}
		else if (M == "size")
		{
			cout << stack.size() << "\n";
		}
		else if (M == "empty")
		{
			if (stack.empty())
			{
				cout << "1\n";
			}
			else
				cout << "0\n";
		}
		else if (M == "top")
		{
			if (stack.empty())
			{
				cout << "-1\n";
			}
			else
				cout << stack.top() << "\n";
		}
	}
}