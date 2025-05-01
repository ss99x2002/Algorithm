#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 준규 한개의 멀티탭 이용
// 자기가 사용하는 전기 용품의 순서를 알아냈고,
// 이를 기반으로 플러그를 뺏는 횟수 최소화하는 방법

// 3구 멀티탭 쓸 때, 전기용품 사용 순서 주어질 때 플러스 빼는 최소 횟수.

int n,k; // n: 멀티탭 구멍 개수, k : 전기용품 사용횟수
// 전기용품 이름이 숫자로 주어지고, 그것이 순서대로 주어지는 것.

int input;
vector<int> tools;
int concent[101];
int answer = 0;


bool comp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0); // 이거 넣어주도록 하자..
    cin.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<n; i++){
        concent[i] = -1; //-1 이면 비어있다는 뜻.
    }

    for (int i=0; i<k; i++){
        cin >> input;
        tools.push_back(input);
    }

    for (int i=0; i<k; i++) {

        bool availableConcent = false;

        for (int j = 0; j < n; j++) {
            if (concent[j] == tools[i]) {
                availableConcent = true;
                break;
            }
            if (concent[j] == -1) {
                availableConcent = true;
                concent[j] = tools[i];
                break;
            }
        }


        if (!availableConcent) {
            //현재 바로 사용가능한 콘센트 없을 때는 -> 누구를 방출할 것인지 정해야 함.
            //다음 등장시기가 가장 느린 애를 뽑아줘야 한다.
            //이 로직이 핵심 로직임 !!.. 이를 어떻게 구현할 것인가?
            vector<pair<int,int>> conPriority; //콘 마다 앞으로 나오는 바로 최신 인덱스 저장
            // 즉 (콘센트 인덱스, 최신 인덱스)
            // 최신인덱스 기준 comp 내림차순 해서 첫번째 나오는게 -> 현재 교체하면 되는 콘센트가 되는 것임.

           for (int con = 0; con < n; con++){
               // concent마다.
               bool isPush = false;
               for (int idx = i+1; idx < k; idx++ ){
                   if (concent[con] == tools[idx]){
                       conPriority.push_back({con,idx});
                       isPush = true;
                       break;
                   }
               }
               if (!isPush){
                   conPriority.push_back({con,k});
               }
           }

           sort(conPriority.begin(), conPriority.end(), comp);
           concent[conPriority[0].first] = tools[i];
           answer ++;
        }
    }
    cout << answer;

}
