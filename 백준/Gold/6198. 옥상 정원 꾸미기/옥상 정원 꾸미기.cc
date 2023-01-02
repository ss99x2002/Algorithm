#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, h;
stack<long long> stk;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long total = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> h;
		while (!stk.empty() && stk.top() <= h)
		{
			stk.pop();
		}
		total = (long long)stk.size() + total;
		stk.push(h);
	}
	cout << total << "\n";
}