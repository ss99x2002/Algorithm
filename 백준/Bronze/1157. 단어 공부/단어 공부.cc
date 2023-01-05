#include <iostream>

using namespace std;
long long arr[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(arr, arr + 26, 0);
	string A;
	cin >> A;

	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] < 97)
		{
			arr[(A[i] + 32) - 'a']++;
		}
		else {
			arr[A[i] - 'a']++;
		}
	}
	int max = -1;
	int maxIdx = -1;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			maxIdx = i;
		}
	}

	int flag = 1;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == max && i!=maxIdx)
		{
			cout << "?";
			flag = 0;
			break;
		}
	}

	if (flag)
	{
		cout << (char)(maxIdx + 65);
	}
}