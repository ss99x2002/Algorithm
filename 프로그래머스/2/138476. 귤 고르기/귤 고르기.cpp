#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Comp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.second < b.second; //second desc 
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;

unordered_map<int,int>m;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for (int i=0; i<tangerine.size(); i++){
        m[tangerine[i]]++;
    }
    
    for (auto & [key,value] : m){
        pq.push({key,value});
    }
    
    int tmpK = k;

    
    while(tmpK>0){
    
       tmpK = tmpK -  pq.top().second;
        answer ++;
       pq.pop();
    }

     
    return answer;
}