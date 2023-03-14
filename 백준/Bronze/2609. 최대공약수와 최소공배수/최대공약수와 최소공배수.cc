#include <iostream>
using namespace std;

int gcd(int n1, int n2) {
	int c = n1 % n2;
	while (c != 0) {
		n1 = n2;
		n2 = c;
		c = n1 % n2;
	}
	return n2;
}

int lcm(int n1, int n2) {
	return (n1 * n2) / gcd(n1, n2);
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << "\n" << lcm(a, b);
}
