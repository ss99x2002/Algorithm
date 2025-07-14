#include <iostream>
using namespace std;

// k칸을 앞으로 점프 or
// 현재온 거리*2에 해당하는 위치로 순간 이동 

// 순간이동 -> 건전지 사용 안줄어듬
// k칸 점프 -> K칸의 건전지 줄어듬

// 아이언슈트로 n만큼 거리 가려고 할 때, 점프는 최소화해서 이동.
// 사용해야하는 건전지 최솟값은 ? 

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int solution(int n)
{
    int ans = 1;
    int tmp = 1;
    
    bool isPowerTwo = isPowerOfTwo(n);
    
    if (isPowerTwo) return ans;
    else {
        while(n!=1){
            if (n%2 == 1){
                ans ++;
            }
            n=n/2;
        }
    }

    return ans;
}