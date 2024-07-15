#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int N, M;
string url, pwd;

int main() {
	
	unordered_map<string, string> map;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> url >> pwd;
		map.insert({ url, pwd });
	}

	for (int i = 0; i < M; i++) {
		cin >> url;
		cout << map.find(url)->second << "\n";
	}


}