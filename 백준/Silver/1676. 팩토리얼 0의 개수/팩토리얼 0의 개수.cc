#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int N5 = 0;
	int N25 = 0;
	int N125 = 0;

	N5 = N / 5;
	N25 = N / 25;
	N125 = N / 125;

	cout << N5 + N25 + N125;

}
