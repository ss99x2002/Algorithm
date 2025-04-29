#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

// 길이가 N인 수열 주어질 때, 그 수열의 합 구한다.
// 수열의 두 수를 묶으려고 한다. (위치 상관없이 묶을 수 있다.)
// 어떤 수를 묶으면, 수열의 합을 구할 때, 묶은 수는 서로 곱한 후 더한다.

// 적절히 묶었을 때 수열 합이 최대되도록.

// 음수는 음수끼리 or 음수가 한개면 0이랑 곱.
// 양수는 양수끼리 곱.

int n;
int num;
vector<long long> pos;
vector<long long> neg;

bool comp(int a, int b){
    return a > b;
}

int main() {
    cin >> n;
    int oneCnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == 1) oneCnt ++;
        else if (num > 0) {
            pos.push_back(num);
        } else {
            neg.push_back(num);
        }
    }

    sort(pos.begin(), pos.end(),comp); //
    sort(neg.begin(), neg.end()); // -5, -4, -3 ..이 순서.

    // 1은 곱하는거 보다 더하는게 더 나음. -> 따라서 oneCnt 만큼 따로 더해주는 것.

    long long sum = 0;
    for (int i=0; i<pos.size(); i+=2){
        if (i == pos.size()-1)  sum = sum + pos[i];
        else sum = sum + (pos[i] * pos[i+1]);
    }
    
    for (int i=0; i<neg.size(); i+=2){
        if (i == neg.size()-1)  sum = sum + neg[i];
        else sum = sum + (neg[i] * neg[i+1]);
    }

    sum = sum + oneCnt;

    cout << sum;
}

