#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string N;
	cin >> N;
	int arr[26];
	fill(arr, arr + 26, 0);
	for (int i = 0; i < N.length(); i++)
	{
		arr[N[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}