#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

int arr1[500001] = {};
int arr2[500001] = {};
using namespace std;


void binarySearch(int n, int k) {
	int low = 0;
	int high = n - 1; 

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr1[mid] == k) {
			cout << 1 << " ";
			return;
		}
		else {
			if (arr1[mid] > k) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}
	cout << 0 << " ";
}

int main() {
	long long n;
	long long input;
	long long m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr1[i] = input;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		arr2[i] = input;
	}

	sort(arr1, arr1+n);


	for (int i = 0; i < m; i++) {
		binarySearch(n, arr2[i]);
	}
}