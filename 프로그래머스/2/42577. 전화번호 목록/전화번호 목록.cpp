#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// 119 구조대, 지영석 번호 앞 3글자 119 -> 구조대는 영석이의 접두사임
// 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false, 없으면 true
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    
    sort(phone_book.begin(), phone_book.end());
    
    for (int i=0; i<phone_book.size()-1; i++){
        if (phone_book[i+1].find(phone_book[i]) ==0 ){
            answer = false;
            break;
        }
    }
    
    return answer;
}