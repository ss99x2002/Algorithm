#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int t, n; //테케, 유저 수
int k; // 친구 관계의 수
int a, b; // user a, user b 친구 관계임
int m; // 미리 구할 쌍 수
int u, v; // 구해야하는 쌍 수 (얘네 둘이 친구인지 아닌지)

// 연결하는 경로 있으면 1, 없으면 0 출력


int parent[1000001];
int rankArr[1000001];

void init() {
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        rankArr[i] = 0;
    }
}

int find(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return false;
    if (rankArr[ra] < rankArr[rb]) {
        swap(ra, rb);
    }
    parent[rb] = ra;
    if (rankArr[ra] == rankArr[rb]) {
        rankArr[ra]++;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for (int s = 1; s <=t; s++) {
        cin >> n;
        init();
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            unite(a,b);
        }

        cin >> m;
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            if (find(u) == find(v)) {
               ans.push_back(1);
            }
            else {
              ans.push_back(0);
            }
        }
        cout << "Scenario " << s << ":" << "\n";
        for (int i=0; i<ans.size(); i++){
            cout << ans[i] << "\n";
        }

        cout << "\n";
    }


    return 0;
}