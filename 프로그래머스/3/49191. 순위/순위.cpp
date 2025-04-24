#include <string>
#include <vector>

using namespace std;

int graph[101][101];
// n명의 권투선수가 권투대회 참여
// 1~n번까지 번호 부여 받음
// 1:1 방식 진행, 만약 a선수 > b선수면 항상 a가 이김.

// 순위 매기려 할 때. 정확하게 순위 매길 수 있는 수 return 

// 플로이드 워셜 문제
// 모든 정점 쌍 간의 최단거리를 구하는 문제. 

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    // -1 : 패배, 0 : 알수없음, 1 : 승리
    
    for (auto &r : results){
        int win = r[0]; 
        int lose = r[1];
        graph[win][lose] = 1;
        graph[lose][win] = -1;
    }
    
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                    graph[j][i] = -1;
                }
               if (graph[i][k] == -1 && graph[k][j] == -1) {
                    graph[i][j] = -1;
                    graph[j][i] = 1;
                }
            }
        }
    }
    
    for (int i=1; i<=n; i++){
        int cnt = 0;
        for (int j=1; j<=n; j++){
            if (i==j) continue;
            if (graph[i][j] != 0) cnt ++;
        }
        if (cnt == n-1) answer ++;
        // 즉 나를 제외한 사람들과 나의 승패가 확실하면, 나의 순위를 지정할 수 있기 때문임. 
    }
    
    return answer;
}