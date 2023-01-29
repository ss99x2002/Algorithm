#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string N;
	while (1){
		bool flag = 1;
		cin >> N;
		if (N == "0") {
			break;
		}
		else {
			for (int i = 0; i < ceil(N.length()/2); i++) {
				if (N[i] != N[N.length() -1- i]) {
					cout << "no" << "\n";
					flag = 0;
					break;
				}
			}
			if (flag) {
				cout << "yes" << "\n";
			}
		}

	}
}
