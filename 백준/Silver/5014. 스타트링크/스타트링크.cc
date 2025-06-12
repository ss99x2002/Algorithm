#include <iostream>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

// 스타트링크는 총 f층으로 이루어진 고층 건물에 사무실 있고,
// 스타트링크는 g층이다.
// 강호가 지금 있는 곳은 s층, 엘베타고 g층으로 이동하려 한다.

// 강호가 탄 엘베는 u : up, d : down만 존재.
// 만약 u, d 위아래에 해당하는 층 없을 때는 엘레베이터 움직이지 않는다.

// 강호가 g층에 도착하려면 버튼 적어도 몇번 눌러야하는 구하기
// 만약 엘베로 g층 갈 수 없다면 'use the stairs'출력

// 첫째줄에 F,S,G,U,D 주어진다.
// 건물은 1층부터 - F층까지 있다.

int f, s, g, u, d;

int dir[2];
long long dist[1000001];
int answer;
bool isMin = false;


void bfs() {
   queue<int> q;
   q.push(s);
   dist[s] = 0;
   while(!q.empty()){
       int cur = q.front();
       q.pop();
       if (cur == g) {
           cout << dist[cur] << "\n";
           return;
       }
       for (int dd : dir){
           int nx = cur + dd;
           if (nx <= 0 || nx > f) continue;
           if (dist[nx] != -1) continue;
           //cout << "nx = " << nx << "\n";
           q.push(nx);
           dist[nx] = dist[cur] + 1;
       }
   }
   cout << "use the stairs" << "\n";
   return;
}

int main() {
    cin >> f >> s >> g >> u >> d;
    // 강호가 s -> g 가기위한 버튼 최솟 값
    dir[0] = u;
    dir[1] = -d;

    for (int i=0; i<=f; i++){
        dist[i] = -1;
    }
    bfs();
}