#include <iostream>
using namespace std;
int main()
{
	string N, M;
	cin >> M;
	cin >> N;
	if (M.length() - 1 >= N.length() - 1)
	{
		cout << "go" << endl;
	}
	else
		cout << "no" << endl;
}