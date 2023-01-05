#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,X;
	string msg;
	deque<int> deq;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> msg;

		if (msg == "push_front")
		{
			cin >> X;
			deq.push_front(X);
		}
		else if (msg == "push_back")
		{
			cin >> X;
			deq.push_back(X);
		}
		else if (msg == "pop_front")
		{
			if (deq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << deq.front() << "\n";
				deq.pop_front();
			}
		}
		else if (msg == "pop_back")
		{
			if (deq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << deq.back() << "\n";
				deq.pop_back();
			}
		}
		else if (msg == "size") {
			cout << deq.size() << "\n";
		}
		else if (msg == "empty")
		{
			if (deq.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (msg == "front")
		{
			if (deq.empty())
			{
				cout << -1 << "\n";
			}
			else cout << deq.front() << "\n";
		}
		else if (msg == "back")
		{
			if (deq.empty()) cout << -1 << "\n";
			else cout << deq.back() << "\n";
		}
	}
}