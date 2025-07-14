#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// 할인하는 제품은 하루에 하나씩 구매할 수 있다.
// 자신이 원하는 제품과 수량이 할인하는 날짜와 10일연속으로 일치하는 경우 회원가입
// sliding window 10개 단위로 하면될듯 .. 

unordered_map<string,int> m;

bool allZero(){
    for(auto [k,v] : m){
        if (v>0){
            return false;
        }
    }
    return true;
}


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for (int i=0; i<want.size(); i++){
        m[want[i]] = number[i];
    }
    
    int st =0;
    int end = 9;
    // 초기 계산
    for (int i=st; i<=end; i++){
        if (m.find(discount[i]) != m.end())  {
            m[discount[i]]--;
        }
    }
    
    if(allZero()) answer++;
    
    for (int i=st+1; i<=discount.size()-10; i++){
         if (m.find(discount[i-1]) != m.end())  {
           m[discount[i-1]]++;
        }
        
         if(m.find(discount[i+end])!=m.end()) {
             m[discount[i+end]]--;   
         }
        if (allZero()) answer++;
    }
    return answer;
}