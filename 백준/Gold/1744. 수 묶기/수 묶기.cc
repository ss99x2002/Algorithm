#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

// 수 합이 최대가 나오게 묶었을 때 합 출력

int n;
vector<int> pos;
vector<int> neg;
int input;
int oneCnt = 0;

bool comp(int a, int b){
    return a> b;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> input;
        if (input <= 0) neg.push_back(input);
        else if (input == 1) oneCnt ++;
        else if (input > 0 ) pos.push_back(input);
    }

    sort(pos.begin(), pos.end(), comp);
    sort(neg.begin(), neg.end()); //-5, -3, -2 ... 0

    int sum = 0;
    for (int i=0; i<pos.size(); i=i+2){
        if (i== pos.size()-1) sum = sum +pos[i];
        else sum = sum+(pos[i] * pos[i+1]);
    }

    for (int i=0; i<neg.size(); i=i+2){
        if (i== neg.size()-1) sum = sum +neg[i];
        else sum = sum+(neg[i] * neg[i+1]);
    }

    cout << sum + oneCnt;


}