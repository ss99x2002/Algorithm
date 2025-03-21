#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer1;
    vector<int> answer;
    stack<int> s;
    
    for (int i=0; i<arr.size(); i++){
        if (s.empty()){
            s.push(arr[i]);
            answer.push_back(arr[i]);
        }
        else {
          if(s.top()!= arr[i]){
            s.push(arr[i]);
                answer.push_back(arr[i]);
        }
    }
        
        
}

    return answer;
}