#include <iostream>
#include <vector>

using namespace std;

// next_permutation 활용도 가능 (조합)

// 1. 폐업 시키지 않을 치킨집 M개 고르기 (조합 -> 즉 A개 중에 M개를 선택하는 것)
// 2. 다 고른 후 도시의 치킨거리 구하기

// 치킨 거리 = 집에서 가장 가까운 치킨집 사이의 거리 (최소거리)
// 치킨 거리 = |r1-r2] + |c1-c2|
// 0 = 빈칸, 1 = 집, 2 = 치킨집

// 도시의 치킨 거리 = 모든 집의 치킨 거리 합 (즉 각 집의 치킨 거리합)
// 치킨집 M개 택했을 때 도시의 치킨 거리 최소 값

// 각 집과 치킨집 거리가 최소여야 함.
// 치킨 거리의 max 값보다 작으면 넣고, 아니면 빼는 식으로 각 집과 치킨거리 구하기.

int n, m;
// n = 도시 행 열
// m = 살릴 치킨 가게 (1~13 사이)

struct Chicken {
    int r, c;
    bool visited;
};

int city[51][51];
vector<pair<int, int>> home;
vector<Chicken> chicken;



int minAns = 102*14;

int checkDistance() {
    int total = 0;
    for (int i = 0; i < home.size(); i++) {
        int minHome = 102;
        for (int j = 0; j < chicken.size(); j++) {
            if (chicken[j].visited) {
                int distance = abs(chicken[j].r - home[i].first) + abs(chicken[j].c - home[i].second);
                if(minHome > distance) {
                    minHome = distance;
                }
            }
        }
        total = total + minHome;
    }
    return total;
}

void dfs(int idx, int count) {
    if (count == m) {
        if (minAns > checkDistance()) {
            minAns = checkDistance();
        }
    }

    for (int i = idx; i < chicken.size(); i++) {
        if (!chicken[i].visited) {
            chicken[i].visited = true;
            dfs(i, count + 1);
            chicken[i].visited = false;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                home.push_back({i, j});
            } else if (city[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    dfs(0, 0);
    cout << minAns;

    return 0;
}