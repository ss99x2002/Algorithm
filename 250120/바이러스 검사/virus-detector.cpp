#include <iostream>
#include <vector>
using namespace std;


//검사팀장
// 검사팀원
// 한 가게당 팀장은 1명, 팀원은 여러명 (팀장 반드시 존재)
// 팀장이든 팀원이든 담당한 가게에 대해서만 검사

// 식당의 수 n
// 각 식당에 있는 고객 수 주어짐
// 검사 팀장이 검사할 수 있는 최대 고객수와, 검사 팀원이 검사할 수 있는 최대 고객수 주어짐

// n개 식당 고객 모두 검사하기 위한 검사자의 최소의 수 출력

int main() {
    long long n,cust;
    long long maxLdr, maxMbr;
    long long answer =0;

    cin >> n;
    vector<long long> restList;

    for (long long i=0; i<n; i++) {
        cin >> cust;
        restList.push_back(cust);
    }
    cin >> maxLdr >> maxMbr;

    for (int i=0; i<n; i++) {
        long long custom = restList[i]-maxLdr;
        answer = answer + 1;
        if (custom > 0 ){
            if (custom % maxMbr == 0) {
                answer = custom/maxMbr + answer;
            }
            else {
                answer = (custom/maxMbr) + 1 + answer;
            }
        }
    }
    cout << answer;
}