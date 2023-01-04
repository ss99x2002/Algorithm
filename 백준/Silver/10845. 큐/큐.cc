#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,X;
	queue<int> q;
	string m;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> m;
		if (m == "push")
		{
			cin >> X;
			q.push(X);
		}
		else if (m == "front")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (m == "back")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.back() << "\n";
			}
		}
		else if (m == "empty")
		{
			if (q.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (m == "size")
		{
			cout << q.size() << "\n";
		}
		else if (m == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else
			{
				cout << -1 << "\n";
			}
		}
	}

}