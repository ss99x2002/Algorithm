#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, A, cnt = 0;
	int idx = -1;
	cin >> N >> M;
	deque<int>deq;
	queue<int> q;

	for (int i = 1; i <=N; i++)
	{
		deq.push_back(i);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A;
		q.push(A);
	}
	while (!q.empty())
	{
		for (int i = 0; i < deq.size(); i++)
		{
			if (deq[i] == q.front())
			{
				idx = i;
				break;
			}
		}

		if (idx < deq.size()-idx)
		{
			while (1)
			{
				if (deq.front() == q.front())
				{
					deq.pop_front();
					q.pop();
					break;
				}
				cnt++;
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		else
		{
			while (1)
			{
				if (deq.front() == q.front())
				{
					deq.pop_front();
					q.pop();
					break;
				}
				cnt++;
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}
	}
	cout << cnt;
}