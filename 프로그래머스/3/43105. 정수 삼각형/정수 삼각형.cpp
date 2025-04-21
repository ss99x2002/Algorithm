#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    
    for (int i=0; i<n; i++){
        for (int j=0; j<triangle[i].size(); j++){
            dp[i][j] = triangle[i][j];
        }
    }
    
    
    for (int i=n-2; i>=0; i--){
        for (int j=0; j<triangle[i].size(); j++){
            dp[i][j] = dp[i][j] + max(dp[i+1][j+1], dp[i+1][j]);
        }
    }
    
    
    answer = dp[0][0];
    
    return answer;
}