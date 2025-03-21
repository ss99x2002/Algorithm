#include <string>
#include <vector>
#include <map>

using namespace std;

// participant : 마라톤 참여 선수들 배열
// completion : 완주한 선수들 배열

// 완주하지 못한 선수들 이름 Return soltion

map<string, int> partc;
map<string,int> comple;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for (int i=0; i<participant.size(); i++){
        if (partc.find(participant[i]) == partc.end()){
            partc.insert({participant[i], 1});
        } else {
            partc.find(participant[i])->second += 1;
        }
    }
    
    for (int i=0; i<completion.size(); i++){
        if (comple.find(completion[i]) == comple.end()){
            comple.insert({completion[i], 1});
        } else {
            comple.find(completion[i])->second += 1;
        }
    }
    
    
    for (int i=0; i<participant.size(); i++){
        if (comple.find(participant[i]) == comple.end()){
            answer = participant[i];
            break;
        } else {
            if (comple.find(participant[i]) -> second != partc.find(participant[i])->second){
                answer = participant[i];
                break;
            }
        }
    }
    
    
    return answer;
}