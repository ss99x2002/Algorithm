#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[10];
int visited[10];


void visitedNumber(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << num[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] != 1) {
            visited[i] = 1;
            num[cnt] = i;
            visitedNumber(cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    visitedNumber(0);
}