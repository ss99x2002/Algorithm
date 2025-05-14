#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

int t,k; //test 케이스 수, k 연산 수
string inputs,num;
int main() {
    cin >> t;

    while(t--){
        vector<string> operations;
        priority_queue<int, vector<int>, greater<int>> minPq;
        priority_queue<int,vector<int>> maxPq;
        unordered_map<int,int> cnt;
        cin >> k;

        for (int i=0; i<k; i++){
            cin >> inputs >> num;
            operations.push_back(inputs + num);
        }
        // 넣은 인풋들 처리
        for (int i=0; i<operations.size(); i++){
            if (operations[i] == "D-1") {
                while(!minPq.empty() && cnt[minPq.top()] == 0)
                    minPq.pop();
                if (!minPq.empty()){
                    cnt[minPq.top()]--;
                    minPq.pop();
                }

            } else if (operations[i] == "D1") {
                // 최대 삭제
                while(!maxPq.empty() && cnt[maxPq.top()] == 0)
                    maxPq.pop();
                if (!maxPq.empty()){
                    cnt[maxPq.top()]--;
                    maxPq.pop();
                }
            } else {
                minPq.push(stoi(operations[i].substr(1)));
                maxPq.push(stoi(operations[i].substr(1)));
                cnt[stoi(operations[i].substr(1))]++;
            }
        }
        while(!minPq.empty() && cnt[minPq.top()] == 0) minPq.pop();
        while(!maxPq.empty() && cnt[maxPq.top()]== 0) maxPq.pop();
        if (minPq.empty() || maxPq.empty()) cout << "EMPTY" << "\n";
        else cout << maxPq.top() <<" "<< minPq.top() << "\n";
    }
}
