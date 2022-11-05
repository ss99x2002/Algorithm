#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, M, num, data;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		queue <pair<int, int>> queue;
		priority_queue <int> pqueue;
		cin >> N >> M;
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> data; //j가 현재 번째 수, data가 우선순위
			queue.push(pair<int, int>(j, data));
			pqueue.push(data);
		}
		while (!queue.empty())
		{
			int location = queue.front().first;
			int data = queue.front().second;
			queue.pop();

			if (pqueue.top() == data)
			{
				++cnt;
				pqueue.pop();
				if (location == M)
				{
					cout << cnt << endl;
					break;
				}
			}
			else
			{
				queue.push(pair<int,int>(location, data));
			}
		}
	}
}

