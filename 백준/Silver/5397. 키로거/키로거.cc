#include <iostream>
#include <list>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	string pwd;
	cin >> N;
	list<char> L;
	list<char> ::iterator it;
	for (int i = 0; i < N; i++)
	{
		L.clear();
		it = L.begin();
		cin >> pwd;
		for (int i = 0; i < pwd.length(); i++)
		{
			if (pwd[i] == '<')
			{
				if (it != L.begin())
				{
					it--;
				}
			}
			else if (pwd[i] == '>')
			{
				if (it != L.end())
				{
					it++;
				}
			}
			else if (pwd[i] == '-')
			{
				if (it != L.begin())
				{
					it = L.erase(--it);
				}
			}
			else if (pwd[i]!='>' && pwd[i]!='<' && pwd[i]!='-')
			{
				L.insert(it, pwd[i]);
			}
		}

		for (it = L.begin(); it != L.end(); it++) {
			cout << *it;
		}
		cout << '\n';
	}
}