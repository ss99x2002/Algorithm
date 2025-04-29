#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;


// 세준이는 양수 +,-, ()로 식을 만들었다.
// 그리고 괄호를 모두 지웠다.
// 그리고 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
// 괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램은?

// 식은 0~9, + -로만 이루어져 있고
// 가장 처음과 마지막 문자는 숫자다.
// 5자리보다 많이 연속되는 숫자는 없다.
// 괄호 쳐서 만드는 식의 최소값을 출력


string cal;

int main() {
    cin >> cal;
    bool beforeMinus = false;

    string num = "";
    int answer = 0;

    // cal.size()까지 i범위를 추가하고, if문에도 넣은 이유 :
    // 자신의 number를 다 확인한 다음에. 다음 수식을 확인하고 계산하기 때문임.
    // 따라서 마지막 index 왔을 때 number가 완성되고, 이를 + 또는 - 해야하므로
    // cal.size()까지 i 범위를 추가해서 본다.
    for (int i=0; i<=cal.size(); i++){
        if (cal[i] == '-' || cal[i] == '+' || i==cal.size()) {
            if (beforeMinus) {
                answer = answer - stoi(num);
                num = "";
            }

            else {
                answer = answer + stoi(num);
                num = "";
            }
        }

        else {
            num = num + cal[i];
        }
        if (cal[i] == '-'){
            beforeMinus = true;
        }
    }

    cout << answer;
}

