#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int n,m;
int x, y;
int p1, p2;

vector<int> vec[101];
bool visit[101] = { 0 };
int cnt = 0;
int flag = 0;

void dfs(int cur) {
    visit[cur] = 1;
    for (int i = 0; i < vec[cur].size(); i++) {
        if (visit[vec[cur][i]] == 1) continue;
        if (vec[cur][i] == y) cout << cnt+1 << "\n";
        cnt++;
        dfs(vec[cur][i]);
        cnt--;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n;
    cin >> x >> y;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2;
        vec[p2].push_back(p1); // p1 = 부모, p2 = 자식
        vec[p1].push_back(p2);
        // 양방향으로 1촌이기 때문에 두개 다 push 함. 
    }
    dfs(x);
    if (visit[y] == 0) cout << -1 << "\n";
}
