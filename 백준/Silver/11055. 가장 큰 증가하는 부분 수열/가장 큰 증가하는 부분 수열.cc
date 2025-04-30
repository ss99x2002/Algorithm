#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;


// 가장 긴 증가 부분 수열의 길이는?

int n;
int dp[1001];
// 점화식 :
// dp[i] = i번째까지 도달할 때 연속된 수열의 수를 의미.
// 따라서 가장 큰 수열의 길이는 -> 연속 수열의 크기가 가장 큰 값을 찾으면 됨.
int nums[1001];
int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }


    for (int i=0; i<n; i++){
       dp[i] = nums[i];
    }


    for (int i=0; i<=n-1; i++){
       int maxV = 0;
        for (int j=i; j>0; j--){
            if (nums[i] > nums[i-j]){
               maxV = max(maxV, dp[i-j]);
            }
        }
        dp[i] = dp[i] + maxV;
    }

    int maxAnswer = 0;

    for (int i=0; i<n; i++){
        maxAnswer = max(maxAnswer, dp[i]);
    }

    cout << maxAnswer;

}

