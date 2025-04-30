#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;


// 가장 긴 증가 부분 수열의 길이는?

int n;
int dp[1001];
int nums[1001];
int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }


    for (int i=0; i<n; i++){
       dp[i] = 1;
    }


    for (int i=0; i<=n-1; i++){
     //  cout << "==== 현재  i = " << i << "\n";
        for (int j=i; j>0; j--){
            if (nums[i] > nums[i-j]){
                dp[i] = max(dp[i-j]+1, dp[i]);
            }
        }

      //  cout << "* dp[i] " << dp[i] << "\n";
    }

    int maxAnswer = 0;

    for (int i=0; i<n; i++){
        maxAnswer = max(maxAnswer, dp[i]);
    }

    cout << maxAnswer;

}

