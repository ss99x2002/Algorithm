#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(pair<int,string>a, pair<int,string>b)
{
	return a.first < b.first;

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,age;
	string name;
	vector <pair<int, string>> vec;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		vec.push_back({ age,name });
	}
	stable_sort (vec.begin(), vec.end(),cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
}