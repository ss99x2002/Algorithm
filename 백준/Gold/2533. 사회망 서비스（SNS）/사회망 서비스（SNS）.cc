#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


// 친구 관계 트리가 주어질 때,
// 모든 개인이 새로운 아이디어를 수용하기 위해 필요한 얼리어답터 수는?

// 백트래킹? bfs? XX
// 트리 DP를 활용해서 푸는 것이다.
// 트리 DP
// 트리 구조 위에서 이루어지는 DP
// 자식 -> 부모 값 전달하며 최적 상태를 계산
// 즉 서브트리 정보를 활용해 상위 노드 정보를 계산하는 방식.

vector<int> graph[1000001];
int dp[1000001][2]; // 0:얼리 아님, 1:얼리
// dp[node][0] = 노드가 얼리가 아닐 때, 서브트리에서 필요한 최소 얼리 수
// dp[node][1] = 노드가 얼리 일 때, 서브트리에서 필요한 최소 얼리 수

// dp[node][0] = dp[child][1] (모든 차일드에 대한 합)
// dp[node][1] = 1 +  각 차일드에 대해 min (dp[child][1], dp[child][0])
bool visited[1000001];
int n;
int u,v;

void dfs(int node){
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = 1;

    for (auto next : graph[node]){
        if (visited[next]) continue;
        dfs(next);
        dp[node][0] = dp[next][1] + dp[node][0];
        dp[node][1] = min (dp[next][1], dp[next][0]) + dp[node][1];
    }
}

int main(){
    cin >> n;
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    cout << min(dp[1][0],dp[1][1]) << "\n";
    return 0;
}
