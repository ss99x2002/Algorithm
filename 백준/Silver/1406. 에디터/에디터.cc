#include <iostream>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	list <char> vec;
	list<char>::iterator iter = vec.end();
	string s;
	char input, add;
	int M;
	cin >> s;
	cin >> M;
	for (char c : s) vec.push_back(c);
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		if (input == 'P')
		{
				cin >> add;
				vec.insert(iter,add);
		}
		else if (input == 'L')
		{
			if (iter != vec.begin())
			{
				iter--;
			}
		}
		else if (input == 'D')
		{
			if (iter != vec.end())
			{
				iter++;
			}
		}
		else if (input == 'B')
		{
			if (iter!=vec.begin())
			{
				iter--;
				iter =vec.erase(iter);
			}
		}
	}
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter;
	}
}
