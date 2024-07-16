#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int K, L;
string studentNum;
string List[500001];

int main() {

    cin.tie();
    ios::sync_with_stdio(0);

    unordered_map<string, int> map;

    cin >> K >> L;
    for (int i = 0; i < L; i++) {
        cin >> studentNum;
        if (map.count(studentNum) != 0) {
            map.find(studentNum)->second = map.find(studentNum)->second + 1;
        }
        else {
            map.insert({ studentNum, 1 });
        }
        List[i] = studentNum;
    }

    int idx = 0;
    int cnt = 0;
    while (cnt < K) {
        if (idx >= L) {
            return 0;
        }
        string student = List[idx];
        if (map.find(student)->second != 1) {
            idx = idx + 1;
            map.find(student)->second = map.find(student)->second-1;
        }
        else {
            cout << student << "\n";
            cnt++;
            idx = idx + 1;
        }
    }

}