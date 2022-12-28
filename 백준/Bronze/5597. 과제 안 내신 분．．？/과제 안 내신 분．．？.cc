#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool arr[31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	vector <int > v;
	for (int i=1; i<=28; i++)
	{
		cin >> N;
		arr[N] = true;
	}

	for (int i = 1; i <=30; i++)
	{
		if (arr[i] != true)
		{
			v.push_back(i);
		}
	}
	
	if (v[0] > v[1])
	{
		cout << v[1] << "\n" << v[0];
	}
	else
	{
		cout << v[0] << "\n" << v[1];
	}
}