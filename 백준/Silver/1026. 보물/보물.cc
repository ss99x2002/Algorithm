#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

// S를 가장 작게 만들기 위해 A수 재배열
// 단 B에 있는 수는 재배열하면 안된다.
// S의 최솟값 출력

int n;
vector<int> a;
vector<int> b;
int input;


bool comp (int a, int b){
    return a > b;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> input;
        a.push_back(input);
    }
    for (int i=0; i<n; i++){
        cin >> input;
        b.push_back(input);
    }

    sort(a.begin(), a.end(), comp);
    sort(b.begin(),b.end());

    int sum = 0;
    for (int i=0; i<n; i++){
        sum = sum + (a[i] * b[i]);
    }

    cout << sum;
}

