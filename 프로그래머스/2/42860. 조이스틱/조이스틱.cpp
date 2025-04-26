#include <string>
#include <vector>
// 1. 조이스틱 상/하 이동 최솟값 구하는(알파벳을 A에서 J 등 목표한 바로 바꾸는) 방법
// A ~ N의 경우 N - character
// O ~ Z의 경우 Z - character + 1

// 그래서 alphaMove[26]을 {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1}; 같이 정의 할 수 있음

using namespace std;


int alphaMove[26] =  {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};
// A - Z까지 A에서 최소로 이동 가능한 알파벳 이동 수를 미리 만들어 둔 배열이다. 
int n;
int solution(string name) {
    int answer = 0;
    n = name.size();
    int minMove = n-1; //최소 커서 이동 거리
    
    for (int i=0; i<name.size(); i++){
        answer = answer + alphaMove[name[i]-'A'];
        
        int y = i+1; //A가 아닌 문자가 있는 위치.
        while(y<name.size() && name[y] == 'A') y++;
        minMove = min(minMove,min((i+i+n-y), (n-y) + n-y + i));   
    }
    answer = answer + minMove;
    return answer;
}