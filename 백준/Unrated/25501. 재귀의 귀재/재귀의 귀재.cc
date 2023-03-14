#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int cnt = 0;
char P[1001];
int recursion(const char* s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P;
        cout << isPalindrome(P) << " " << cnt << "\n";
        cnt = 0;
    }
}