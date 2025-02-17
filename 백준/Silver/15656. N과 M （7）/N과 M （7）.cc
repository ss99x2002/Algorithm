#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int input;
vector<int> num;
int visited[9];
int ans[9];

//n개의 수와 m개를 고르는 수열
//num 에는 N개의 수가 담김 (배열 되어있는 숫자가 아님)


void checkBackTracking(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        ans[cnt] = num[i];
        checkBackTracking(cnt + 1);
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input;
        num.push_back(input);
    }

    sort(num.begin(), num.end());
    checkBackTracking( 0);
}