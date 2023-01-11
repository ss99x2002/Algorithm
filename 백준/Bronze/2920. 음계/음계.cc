#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> vec;
	int flag = 0,n;
	for (int i = 0; i <8; i++)
	{
		cin >> n;
		vec.push_back(n);
		if (i == 0 && vec[0] == 8)
		{
			flag = 8;
		}
		else if (i == 0 && vec[0] == 1)
		{
			flag = 1;
		}

		if (flag == 8 && i!=0)
		{
			if (vec[i] != vec[i - 1] - 1)
			{
				flag = 0;
			}
		}

		if (flag == 1 && i!=0)
		{
			if (vec[i] != vec[i - 1] + 1)
			{
				flag = 0;
			}
		}
	}
	if (flag != 0 && !vec.empty() && vec[0] == 1)
	{
		cout << "ascending";
	}
	else if (flag != 0 && !vec.empty() && vec[0] == 8)
	{
		cout << "descending";
	}
	else
		cout << "mixed";
}