#include <string>
#include <vector>
#include <stack>
#include <algorithm>

// 구명보트 작아서 최대 2명씩 밖에 탈 수 없음.
// 무게 재한 존재.
// 구명보트 최대한 적게 사용해서 모든 사람 구출
// 모든 사람 구출 위해 필요한 구명보트 갯수 최솟값 return. 

// 투포인터 + 정렬 활용.
// 투포인터란? 
// 2개의 포인터(인덱스)를 활용해서 배열을 탐색하는 알고리즘 기법.
// left (시작), right(끝) 두 포인터를 설정해서 문제를 푼다. 

// 최대한 적게 사용하기 위해서는 => 무거운 사람 + 가벼운 사람 조합 -> 구명보트 최소화.
// 따라서 투포인터로 이런 조합을 찾아내는 것이다. 
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort (people.begin(), people.end());
    
    int left = 0;
    int right = people.size()-1;
    
    while(left <= right){
        if (people[left] + people[right] <= limit){
            left ++;
            right --; //무거운 사람이랑 적은 사람 같이 태워서 보트 보냄.
        } 
        else {
            right --; //무거운 사람만 보트 보냄. 
        }
        answer ++;
    }
    return answer;
}