#include <string>
#include <vector>
#include <algorithm>

// 가장 짧은 시간은? -> 1분만에 심사 가능한 심사위원일 경우
// 가잔 긴 시간은? -> 심사위원 중 가장 심사 느린 사람에게 모두 몰리는 경우

// 처리 가장 느린 심사위원 속도 * n명 사람 = 최대시간
// n = 최소시간

// 최대 시간 - 최소시간 기준으로 이분 탐색을 진행한다!
// ex) 30분으로 잡으면 7분 심사위원은 4명, 10분 심사위원은 3명 처리 가능
// 최소 시간이므로 더 줄이는 시간을 찾아서 계속 이분 탐색. 

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end()); 
    long long minV = 1;
    long long maxV = n * (long long)times.back(); 
    
    while(minV <= maxV){
        long long avgV = (minV + maxV)/2;
        long long tmp = 0;
        
        for (int i=0; i<times.size(); i++){
            tmp = tmp + (avgV/(long long)times[i]); 
            //현재 avg 30일때 times = 7인 심사위원은 4
            // times = 10인 심사위원은 3 더함.
        }
        
        if (tmp >= n){
            maxV = avgV - 1;
            answer = avgV;
        }
        else minV = avgV + 1;
    }
    return answer;
}