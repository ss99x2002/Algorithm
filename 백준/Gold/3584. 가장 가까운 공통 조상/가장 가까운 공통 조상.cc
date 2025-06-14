#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

// 루트가 있는 트리가 주어지고,
// 트리 상 두 정점 주어질 때, 그들의 가장 가까운 공통 조상
// 두 노드를 모두 자손으로 가지면서 깊이가 가장 깊은 (즉 두 노드에 가장 가까운 노드) 노드 의미.

// 두 노드 주어질 때, 가장 가까운 조상 찾는 프로그램.

int t, n; // n=트리 구성 노드 수
int a, b; // a= b의 부모라는 뜻.


int parent[10001];
// parent[b] = a; 즉 b 배열보면 바로 직계 부모를 알 수 있도록 저장함.

void initParent() {
    for (int i = 0; i < 10001; i++) {
        parent[i] = -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        initParent();
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            parent[b] = a;
        }
        cin >> a >> b; // 공통 조상 구할 노드 두개.
        
        vector<bool> seen(n+1,false);
        int cur = a;
        while(cur != -1){
            seen[cur] = true;
            cur = parent[cur];
        }
        
        cur = b;
        while(!seen[cur]){
            cur = parent[cur];
        }
        
        cout << cur << "\n";
        
    }
}