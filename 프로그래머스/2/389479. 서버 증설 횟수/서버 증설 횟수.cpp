#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 키포인트 : m 명 늘어날때마다 서버1대 추가 필요
// m명미만이면 서버 증설 불필요. 

// m: 서버 증설 필요 단위
// k : 서버 유지 시간

int solution(vector<int> players, int m, int k) {
    queue<pair<int,int>> q; // {서버 증설 갯수, 종료시간}
    int answer = 0;
    int curServer = 0; 
    for (int i=0; i<players.size(); i++){
        if (i == (q.front().second)){
            curServer = curServer - (q.front().first);
            q.pop();
        }
        
        if (int(players[i]/m) > curServer){
            int requireServer = (players[i]/m) - curServer;
            curServer = curServer + requireServer;
            q.push({requireServer, i + k});
            answer = answer + requireServer;
        } else {
            continue;
        }
    }
    return answer;
}