#include <string>
#include <vector>
#include <iostream>

//사전 A E I O U 만 사용해서 만들 수 있는 5자 이하 단어 수록 됨.
// 하나 단어가 몇번째 단어인지 return하는 solution 완성.
using namespace std;

vector<string> alphabets = {"A","E","I","O","U"};
string copyW;
int answerCnt;
int cnt = 0;
bool found = false;
void backTraking (string wrd){

    if (wrd == copyW){
        answerCnt = cnt;
        found = true;
        return;
    }
    
    if (wrd.size()>=5) return;
    
    for (int i=0; i<5; i++){
        cnt ++;
        backTraking(wrd + alphabets[i]);
        if (found) return;
    }
}

int solution(string word) {
    int answer = 0;
    copyW = word;
    backTraking("");
    return answerCnt;
}