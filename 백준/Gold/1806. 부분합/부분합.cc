#include <iostream>
#include <algorithm>

using namespace std;

// 이 수열에서 연속된 수들의 부분합 중에
// 합이 s가 되는 것 중 가장 짦은 것의 길이는?

long long n, s, num;
long long sum = 0;
int minLen = 100001;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }

    int left = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + a[i];
        while (sum >= s) {
            minLen = min(minLen, i - left + 1);
            sum = sum - a[left++];
        }
    }

    if(minLen == 100001){
        cout << 0;
        return 0;
    }
    else {
        cout << minLen << "\n";
    }
}