#include <iostream>
#include<string>
#include <stack>
using namespace std;

// 문자열에서 같은 알파벳이 2개 붙어있는 짝을 찾는다.
// 둘을 제거한 뒤, 앞뒤로 문자열을 이어 붙인다.
// 이 과정을 반복해서 문자열을 모두 제거한다면 짝지어 제거하기가 종료된다.

// s가 주어질 때, 짝지어 제거하기를 성공적으로 수행할 수 있는지 반환하는 함수 완성.
// 성공적 수행하면 1, 아닐경우 0 return 

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    
    for (int i=0; i<s.size(); i++){
        if (st.empty()) {
            st.push(s[i]);
        } else {
            if (st.top() == s[i]){
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
    }
    
    if (st.empty()) return 1;
    else return 0;
}