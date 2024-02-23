#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

// 주어진 항공권 모두 이용한 여행경로 
// tickets : 항공권 정보
// 방문하는 경로를 배열에 담아 return 

vector<string> answer;
bool visited[10001];
bool dfs(string start,int cnt,vector<vector<string>>&tickets) {
    if (cnt == tickets.size()) return true;
    
    for (int i=0; i<tickets.size(); i++) {
        if (visited[i] == true || start != tickets[i][0]) continue;
        visited[i] = true;
        answer.push_back(tickets[i][1]);
        bool isOkay = dfs(tickets[i][1],cnt+1,tickets);
        if (isOkay) return true;
        visited[i] = false;
        answer.pop_back();
    }
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end());
    answer.push_back("ICN");
    dfs("ICN",0,tickets);
    return answer;
}