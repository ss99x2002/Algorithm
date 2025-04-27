#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 강을 가로 지르는 하나의 차선으로 된 다리가 있다.
// 이 다리를 n개의 트럭이 건너려 한다.
// 트럭 순서 바꿀 수 없다.
// 다리에는 단지 w 대 트럭만 동시에 올라 올 수 있고,
// 다리의 길이는 w 단위길이 이며,
// 각 트럭들은 1초에 1만큼 이동 가능.
// 트럭 들의 무게 합은 다리 최대하중인 L보다 작거나 같아야 한다.

// 길이 =1당, 하나 올라올 수 있음.

// 모든 트럭이 다리 건너는 최단 시간?

int n,w,l;
int truck;
vector<int> trucks;


int main(){
    cin >> n >> w >> l;

    queue <int> q;// 다리

    for (int i=0; i<n; i++){
        cin >> truck;
        trucks.push_back(truck);
    }

    for (int i=0; i<w; i++){
        q.push(0);
    }

    int sum = 0;
    int nextIdx = 0;
    int time = 0;
    while(!q.empty()){
        sum = sum-q.front(); //시간 지날 때 마다 나가는 것이 있기 떄문. 만약에 트럭 없다면 0이 채워서 변동 없도록 함.
        q.pop();
        time ++; // 시간이 지난다.
        if (nextIdx < trucks.size()) { //index가 유효하다면
            if (sum + trucks[nextIdx] <= l) { //하중을 견딜 수 있는 아이라면, 다리에 싣기.
                sum = sum + trucks[nextIdx];
                q.push(trucks[nextIdx]);
                nextIdx++;
            } else {
                q.push(0); // 하중 견딜 수 있을 때 만큼까지. 0으로 채워서 기다리기.
            }
        }

    }
    cout << time;
}

