#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void hanoi(int a, int b, int n) {
	if (n == 1) {
		cout << a << " " << b << "\n";
		return;
	}
	hanoi(a, 6 - a - b, n - 1);
	cout << a << " " << b << "\n";
	hanoi(6 - a - b, b, n - 1);
}
int main()
{
	int N;
	cin >> N;
	cout << (1<<N) - 1 << "\n";
	hanoi(1, 3, N);
}
