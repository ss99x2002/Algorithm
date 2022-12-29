#include <iostream>
#include <stack>
using namespace std;

bool arr[100000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, h;
	stack<pair<int, int>> stk;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> h;
		while (!stk.empty()) {
			if (stk.top().second > h)
			{
				cout << stk.top().first << " ";
				break;
			}
			stk.pop();
		}

		if (stk.empty())
		{
			cout << "0 ";
		}

		stk.push({ i,h });
	}
}