#include <iostream>
#include <stack>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	int K, N, total;
	total = 0;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> N;
		if (N == 0)
		{
			total = total - s.top();
			s.pop();
		}
		else {
			s.push(N);
			total = total + N;
		}
	}
	cout << total;
}