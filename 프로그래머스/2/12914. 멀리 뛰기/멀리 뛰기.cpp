#include <string>
#include <vector>

// 2:47

// 한번에 1칸 또는 2칸 뛸 수 있다.
// 효진이가 끝에 도달하는 방법이 몇가지인지, 거기에 %1234567 나머지 리턴 

using namespace std;

int dp[2001]; 

long long solution(int n) {
    long long answer = 0;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%1234567; 
    }
    
    return dp[n];
}