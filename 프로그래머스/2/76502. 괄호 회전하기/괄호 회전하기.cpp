#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

// [],(),{} 올바른 괄호 문자열이다.
// A가 올바른 괄호 문자열이면 -> [A], (A), {A}도 올바른 문자열
// []가 올바른 문자열이면 ([]) 도 올바른 문자열
// A,B가 올바른 문자열이면 AB

// s를 왼쪽으로 x만큼 회전시킬 때, s가 올바른 문자열이 되도록 하는 x의 개수 return 

// 문자열 왼쪽으로 이동 
void moveLeft(string &s){
    int tmp = s[0];
    for (int i=1; i<s.size(); i++){
        s[i-1] = s[i];
    }
    s[s.size()-1] = tmp;
}
 
int solution(string s) {
    int answer = 0;
    int sLen = s.size();
    for (int k=0; k<sLen; k++){
      stack<char> st;
      bool flag = false;
      for (int i=0; i<sLen; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
            flag = true;
        }
        else if (s[i] == ')'){
            if (!st.empty() && st.top() == '('){
                st.pop();
            }
        }
        
        else if (s[i] == ']'){
             if (!st.empty() && st.top() == '['){
                st.pop();
            }
        }
        else if (s[i] == '}'){
             if (!st.empty() && st.top() == '{'){
                st.pop();
            }
        }
    }
     if (st.empty() && flag ) answer ++;
     moveLeft(s);
   }
    return answer;
}