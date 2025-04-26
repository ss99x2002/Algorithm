#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// ATM 1대 뿐이다. 1~N번 사람 있을 때.
// i번 사람이 돈 인출하는데 걸리는 시간 Pi분

// 각 사람이 돈을 인출하는데 필요한 합의 최솟값은?

// P2 = P1 + p2 걸림. 

int n,num;
vector<int> people;
vector<int> sums;
int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> num;
        people.push_back(num); 
    }
    
    sort (people.begin(),people.end());
    int sum = 0;
    for (int i=0; i<n; i++){
        sum = sum + people[i];
        sums.push_back(sum);
    }
    sum = 0;
    for (auto i : sums){
        sum = sum + i;
    }
    
    cout << sum;
}