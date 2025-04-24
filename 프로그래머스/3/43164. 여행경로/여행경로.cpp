#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ICN에서 출발
// 방문하는 공항 경로 배열 담아 Return 
//[a,b]는 a-b 항공권 있다는 뜻
// 경로 2개 이상일 경우, 알파벳 순서 먼저 경로 return

vector<vector<string>> copyT;
vector<vector<string>> allPath;
vector<string> path;
bool visited[10001];

// 모든 경로를 다 탐색해야 한다는 것을 잊지 말자.

void dfs (string cur, int depth){
    path.push_back(cur);
    if (depth == copyT.size()){
        allPath.push_back(path);
        path.pop_back();
        return;
    }
    
    for (int i=0; i<copyT.size(); i++){
        if (!visited[i] && copyT[i][0] == cur){
         visited[i] = true;
         dfs(copyT[i][1], depth+1);
         visited[i] = false;
        }
    }
    path.pop_back();
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    copyT = tickets;
    sort (copyT.begin(), copyT.end());
  
    dfs("ICN", 0);
    sort(allPath.begin(),allPath.end());
    
    return allPath[0];
}