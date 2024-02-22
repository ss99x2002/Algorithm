#include <string>
#include <vector>
#include <queue>

using namespace std;
int answer;
queue<pair<string,int>> q;
bool visited[51];


bool compareWords(string w1, string w2) {
    int cnt = 0;
    for (int i = 0; i < w1.length(); i++) {
        if (w1[i] == w2[i]) {
            cnt++;
        }
    }

    if (cnt == w1.length() - 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {

    int flag = 0;
    string start = begin;
    string end = target;

    for (auto w : words) {
        if (w == end) {
            flag = 1;
        }
    }

    if (flag == 0) {
        return 0;
    }

    q.push({start,0});

    while (!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == end) {
            answer = cnt;
        }
        for (int i = 0; i < words.size(); i++) {
            if (compareWords(cur, words[i]) == false || visited[i] == true) continue;
             q.push({words[i],cnt+1});
             visited[i] = true;     
        }
    }
    return answer;
}