#include<string>
#include <iostream>
#include <stack>

using namespace std;

stack<char> st;


bool solution(string s)
{
    bool answer = true;

    for (int i=0; i<s.size(); i++){
        if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            if (!st.empty() && st.top() == '(') {
             st.pop();  
            }
            else {
                return false;
            }
        }
    }
    
    if (st.empty()){
        answer = true;
    } else {
        answer = false;
    }

    return answer;
}