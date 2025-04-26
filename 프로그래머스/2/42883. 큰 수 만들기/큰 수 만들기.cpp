#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <string>

using namespace std;
// 어떤 숫자에서 k개의 수를 제거했을 때 가장 큰 숫자.
// 1924에서 2개 제거 시, 가장 큰 숫자 94

// 넣는 수가 나보다 작으면 그냥 넣고,
// 넣는 수가 나보다 크면 나를 빼고, 그 숫자를 넣는다.
// 숫자 자리 순서가 유지되므로, 더 큰 수가 앞으로 땡겨 올 수 있도록 뒤에 자리들을 맞춰서 최대 값을 만들고자 한다.

string solution(string number, int k) {
    int copyK = k;
    
    string answer = "";
    stack<int> s; 
    
        for (int i=0; i<number.size(); i++){
          while (!s.empty() && s.top() < number[i]-'0' && k >0){
                    s.pop();
                    k--;
                }
                 s.push(number[i]-'0');            
            }
        
        while (k>0) {
            s.pop();
            k--;
        }
    
       while(!s.empty()){
           answer = to_string(s.top()) + answer;
           s.pop();
       }
  
    return answer;
}