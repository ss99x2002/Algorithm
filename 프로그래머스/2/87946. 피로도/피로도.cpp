#include <string>
#include <vector>

using namespace std;
// 던전마다 탐험하는데 필요한 '최소 필요 피로도'
// 던전 탐험 마쳤을 때 소모되는 '소모 피로도'
// 즉 소모피로도 -> 던전 탐험하면 소모되는 피로도를 의미.

// 하루에 최대한 많은 던전 탐험하려고 함. 
// 유저가 탐험 가능한 최대 던전수는 ? 

// 해결방법 : 백트래킹?
// k : 유저 현재 피로도
// dungeons : [최소 필요 피로도, 소모 피로도] 던전별 담김.
int dSize;
int answerCnt = 0;
int cnt =0;

bool visited[9] = {false};
vector<vector<int>> dungeonList; 

void backTraking(int curUser, int cnt){
     
    for (int i=0; i<dSize; i++){
       if(visited[i]) continue;
        if (curUser >= dungeonList[i][0]) {
            visited[i] = true;
            backTraking(curUser-dungeonList[i][1], cnt +1);
            visited[i] = false;
        }
    }
    answerCnt = max(answerCnt, cnt);
    return;
}


int solution(int k, vector<vector<int>> dungeons) {
    
    dSize = dungeons.size();
    dungeonList = dungeons;
    backTraking(k,0);
    
    return answerCnt;
}