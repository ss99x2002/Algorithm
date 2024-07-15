#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int N, M;
string pocketmon;
string question;
string L[100001];

int main() {
    cin.tie(0); 
    ios::sync_with_stdio(0);
    unordered_map <string,int> map;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> pocketmon;
        map.insert({ pocketmon,i });
        L[i]=pocketmon;
    }

    for (int i = 0; i < M; i++) {
        cin >> question;
        if (atoi(question.c_str()) != 0 || question.compare("0") == 0) {
            // 숫자인 경우
            cout << L[stoi(question)] << "\n";
        }
        else {
            //문자인 경우
            auto index = map.find(question);
            cout << index->second <<"\n";
        }
    }
}