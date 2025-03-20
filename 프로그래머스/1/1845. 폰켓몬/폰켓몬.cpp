#include <vector>
#include <map>
using namespace std;

// 입력 : 포켓몬 종류들 번호 나열
// 출력 : n/2 마리 포켓몬 선택 방법 중, 가장 많은 포켓몬 선택하는 방법 찾아서 갯수 return 

map<int,int> poketmon;
int cnt = 0;
int answer = 0;

int solution(vector<int> nums)
{ 
    for (int i=0; i<nums.size(); i++){
     if (poketmon.find(nums[i]) == poketmon.end()){
         cnt ++;
         poketmon.insert({nums[i],1});
     }
     else {
        poketmon.find(nums[i])->second = poketmon.find(nums[i])->second +1;
     }
 }
    
    if(nums.size()/2 < cnt){
        answer = nums.size()/2;
    }
    else {
        answer = cnt;
    }
    
    return answer;
}