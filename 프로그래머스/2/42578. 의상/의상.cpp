#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,vector<string>> mapClo;
// 코니는 하루에 최소 한 개 이상 의사 의상 입음
// 코니 의상 담긴 2차원 배열 주어질 때 서로 다른 옷 조합 return 
// 종류별로 최대 1가지 의상 착용 가능 

// [의상 이름, 의상종류임]
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for (int i=0; i<clothes.size(); i++){
        if (mapClo.find(clothes[i][1]) == mapClo.end()){
            vector<string> vecClo;
            vecClo.push_back(clothes[i][0]);
            mapClo.insert({clothes[i][1], vecClo});
        } else {
            mapClo.find(clothes[i][1])->second.push_back(clothes[i][0]);
        }
    }
    
    
    for (auto i=mapClo.begin(); i!= mapClo.end(); i++){
        answer = (i->second.size()+1) * answer;
    }
    
    
    return answer-1;
}