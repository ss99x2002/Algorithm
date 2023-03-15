#include <iostream>
#include <vector>
using namespace std;
int visited[9], N;
vector <int> v;

void dfs() {
    if (v.size() == N) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            v.push_back(i);
            dfs();
            visited[i] = 0;
            v.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    fill(visited, visited +9, 0);
    dfs();
}