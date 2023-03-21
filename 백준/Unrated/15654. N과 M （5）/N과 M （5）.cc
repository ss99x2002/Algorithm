#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10001];
bool visited[10001];
int N, M, n;
vector<int> a;

void dfs(int d) {
    if (d == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <=N; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        arr[d] = a[i-1];
        dfs(d + 1);
        visited[i] = 0;
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i <N; i++) {
        cin >> n;
        a.push_back(n);
    }
    sort(a.begin(), a.end());
    dfs(0);
}