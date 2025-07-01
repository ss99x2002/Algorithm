#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// 문자열 s에 0개 이상의 문자를 문자열 뒤에 추가해서 팰린드롬 만들려고 한다.
// 가능하면 짧은 문자여릉ㄹ 마늗ㄹ려고 한다.

// 동호가 만들 수 있는 가장 짧은 팰린드롬의 길이는?

string s;

int main() {
    cin >> s;
    int n = s.size();
    
    for (int i=0; i<n; i++){
        bool ok = true;
        int left = i;
        int right = n-1;
        while(left < right){
            if (s[left] != s[right]) {
                ok = false;
                break;
            }
            left ++;
            right --;
        }
        
        if (ok) {
            cout << (n+i) << "\n";
            return 0;
        }
    }
    
    
    return 0;
}