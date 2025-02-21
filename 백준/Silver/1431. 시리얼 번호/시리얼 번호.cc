#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string input;
vector<string> serial;


bool comp(const string &s1, const string &s2) {
    if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }

    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (isdigit(s1[i])) {
            sum1 = sum1 + (s1[i] - '0');
        }
    }

    for (int i = 0; i < s2.length(); i++) {
        if (isdigit(s2[i])) {
            sum2 = sum2 + (s2[i] - '0');
        }
    }
    if (sum1 != sum2) return sum1 < sum2;

    return s1 < s2;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        serial.push_back(input);
    }

    sort(serial.begin(), serial.end(), comp);


    for (int i = 0; i < n; i++) {
        cout << serial[i] << "\n";
    }
}