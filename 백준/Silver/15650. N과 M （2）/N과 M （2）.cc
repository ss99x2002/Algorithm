#include <iostream>
#include <vector>
using namespace std;

int arr[10001];
bool visited[10];
int N, M;

void dfs(int num, int d) {
    if (d == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = num; i <=N; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        arr[d] = i;
        dfs(i+1,d + 1); 
        visited[i] = 0;
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    dfs(1,0);
}