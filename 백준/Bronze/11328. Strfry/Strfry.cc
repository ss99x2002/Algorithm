#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	string a, b;

	int alphabet[26];

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		bool possible = true;
		cin >> a >> b;
		fill(alphabet, alphabet + 26, 0);
		for (int i = 0; i < a.length(); i++)
		{
			alphabet[a[i] - 'a']++;
			alphabet[b[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] != 0)
			{
				possible = false;
				break;
			}
		}
		if (possible)
		{
			cout << "Possible\n";
		}
		else
		{
			cout << "Impossible\n";
		}
	}
}
