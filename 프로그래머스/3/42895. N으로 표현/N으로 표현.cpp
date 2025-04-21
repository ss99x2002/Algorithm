#include <string>
#include <vector>
#include <set>

using namespace std;
// N 1~9까지를 최대 8번까지 사용가능 할 때
// N을 최소로 사용하고 사칙연산을 활용하여 number를 만들 수 있는 최소 갯수

set<int> dp[9];

int solution(int N, int number){
    
    if(N == number) return 1;
    
    for (int i=1; i<=8; i++){
        int repeated = 0;
        for (int k=0; k<i; k++){
            repeated = repeated * 10 + N;
        }
        dp[i].insert(repeated);
        for (int j=1; j<i; j++){
            for (int a : dp[j]) {
                for (int b : dp[i-j]) {
                    dp[i].insert (a+b);
                    dp[i].insert (a-b);
                    dp[i].insert (a*b);
                    if (b!=0)   dp[i].insert (a/b);
                }
            }
        }
                            if (dp[i].count(number)) return i;
    }
    
    return -1;
}