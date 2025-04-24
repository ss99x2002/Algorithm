#include <string>
#include <vector>

using namespace std;

//begin에서 target으로 바꿀 때, 몇단계 과정을 거쳐서 변환할 수 있는지.
//한 번의 한 개의 알파벳만 바꿀 수 있다. 

vector<string> copyW;
string copyT;
int minAnswer = 52;
bool visited[52] = {false};

void dfs(int idx, int cnt){
    if (copyW[idx] == copyT){
        minAnswer= min(minAnswer,cnt);
        return;
    }
    
    for (int i=0; i<copyW.size(); i++){
        if (!visited[i]){
            int cntW = 0;
            for (int j=0; j<copyW[idx].size(); j++){
                if (copyW[i][j] != copyW[idx][j]){
                    cntW ++;
                }
            }
            if (cntW == 1){
                visited[i] = true;
                dfs(i,cnt+1);
                visited[i] = false;
            }
        }
    }   
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    copyT = target;
    copyW = words;
    
    
    for (int i=0; i<words.size(); i++){
        int diff = 0;
        for (int j=0; j<begin.size(); j++){
            if (begin[j] != words[i][j]) diff ++;
        }
        if (diff == 1) 
        {
            visited[i] = true;
            dfs(i,1);
            visited[i] = false;
        }
    }
    
    if (minAnswer == 52) return 0;
    
    return minAnswer;
}