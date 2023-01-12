#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
	{
		return a < b;
	}
	else
		return a.length() < b.length();
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	string b;
	vector<string> vec;
	for (int i = 0; i < N; i++)
	{
		cin >> b;
		auto it = find(vec.begin(), vec.end(), b);
		if (it==vec.end())
		{
			vec.push_back(b);
		}
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i=0; i<vec.size(); i++)
	{
		cout << vec[i] << '\n';
	}
}