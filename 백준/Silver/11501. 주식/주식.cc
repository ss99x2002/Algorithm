#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

// 매일 이 세가지 중 하나의 행동을 함.

// 주식을 하나 산다.
// 원하는 만큼 가지고 있는 주식을 판다.
// 아무것도 안한다.

// 날 별로 주식의 가격을 알려줄 때, 최대 이익이 얼마나 되는지 계산
// 테스트별 최대 이익을 나타내는 정수 출력

int t;
int n;
long long input;

int main() {
   cin >> t;
   while(t--){
       cin >> n;
       vector<long long> stocks;
       for (int i=0; i<n; i++){
           cin >> input;
           stocks.push_back(input);
       }
       long long curMax = -1;
       long long totalBenefit = 0;
       // 뒤에서부터 탐색하여, 현 순간의 최고가를 탐색 가능하도록 함.
       // 2 1 3 1 1 의 경우 3에서도 판매하고, (그 이후로 떨어지니 현재 최고가)
       // 2에서도 판매해서 (1->2)에서 상승하니..
       // 각 최고가인 순간을 판단해서 판매 가능해짐.
       for (int i=stocks.size()-1; i>=0; i--){
           if (stocks[i] > curMax){
               curMax = stocks[i];
           }
           else {
               totalBenefit = totalBenefit + (curMax - stocks[i]);
           }
       }

       cout << totalBenefit << "\n";
   }
}

