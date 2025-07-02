#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// N+1개의 집합 있을때, 합집합 연산과, 두 원소 같은 집합 포함 확인 연산
// 0 : a,b -> 합집합
// 1: a,b -> 같은 집합인지 확인 (맞으면 yes, 아니면 no)

int n, m;
int parent[1000001];
int rankArr[1000001];
int a, b, op;


int find(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

bool unions(int a, int b) {
    int ra = find(a); //a의 root;
    int rb = find(b);
    if (ra == rb) return false; //둘이 같은 root unite 필요 x

    if (rankArr[ra] < rankArr[rb])
        swap(ra, rb);
    parent[rb] = ra;
    if (rankArr[ra] == rankArr[rb]) {
        rankArr[ra]++;
    }
    return true;
}

void init() {
    for (int i = 0; i <= n; i++) {
        rankArr[i] = 0;
        parent[i] = -1;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    init();
    while (m--) {
        cin >> op >> a >> b;
        if (op == 0) {
            // 합칩합
            unions(a, b);
        } else if (op == 1) {
            // find 연산
            if (find(a) == find(b)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}