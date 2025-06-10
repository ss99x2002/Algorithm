#include <iostream>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

// 출발은 상그이네 집에서 하고 -> 맥주 한박스 들고 출발
// 맥주 한 박스에는 맥주 20개 들어있다.
// 50미터에 한 병씩 마시려고 한다.
// 즉 50미터를 가려면 그 직전에 맥주 한병 마셔야 한다.


// 맥주 더 구매할 수도 있다.
// 편의점 들리면 빈 병 버리고 새 맥주병 살 수 있다.
// 박스에 있는 맥주는 20병을 넘을 수 없다.
// 편의점 나선 직후에도 50미터 가기 전 맥주 한병 마셔야 한다.

//편의점, 상근이네 집, 펜타포트 좌표가 주어질 때
// 상근이와 친구들이 페스티벌에 도착할 수 있는지 ?


int t, n;
int x, y;
vector<pair<int, int>> store;
vector<pair<int, int>> loca; // [0] 상근 집, [1] 펜타
bool visited[101]; //편의점의 방문을 저장하는 것. (첫번째 편의점, 두번째 편의점 이렇게 지정할 예정)

bool bfs(int homeX, int homeY) {
    queue<pair<int, int>> q;
    q.push({homeX, homeY});
    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();

        if ((abs(loca[1].first - qx) + (abs(loca[1].second - qy)) <= 1000)) {
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue; //이미 방문한 편의점은 지나치기
            }
            if ((abs(store[i].first - qx) + (abs(store[i].second - qy)) <= 1000)) {
                visited[i] = true;
                q.push({store[i].first, store[i].second});
            }
        }
    }
    return false;
}


int main() {
    cin >> t; // 테케 갯수

    while (t--) {
        cin >> n; // 편의점 갯수 n
        cin >> x >> y;
        loca.push_back({x, y});// 집
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            store.push_back({x, y});
        }
        cin >> x >> y;
        loca.push_back({x, y}); //펜타

        if (bfs(loca[0].first, loca[0].second)) {
            cout << "happy" << "\n";
        } else {
            cout << "sad" << "\n";
        }
        fill(visited, visited+101, false);
        loca.clear();
        store.clear();
    }
}