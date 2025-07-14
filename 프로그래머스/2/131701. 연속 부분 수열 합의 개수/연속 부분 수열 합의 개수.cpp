#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

//sliding window?? 사용 해도될거같은데

unordered_set<int> s;

void sumWindows(vector<int> ele, int n){
    int st = 0;
    int en = st+n;
    int sum = 0;
    for (int i=st; i<st+n; i++){
        sum = sum + ele[i%ele.size()];
    }
    s.insert(sum);
  //  cout << "* 시작 " << sum << "\n";
    for (int i=st+1; i<ele.size(); i++){
        sum = sum-ele[(i-1)%ele.size()] + ele[(i+n-1)%ele.size()];
       // cout << sum << "\n";
        s.insert(sum);
    }
}

int solution(vector<int> elements) {
    int answer = 0;
    int maxWindows = elements.size();
    
    for (int i=1; i<=maxWindows; i++){
        // 슬라이딩 윈도우 진행 
        // 더한 부분 수열 합은 -> set에 저장 -> set의 크기를 ans로 반환
        sumWindows(elements, i);
    }
    
    
    return s.size();
}