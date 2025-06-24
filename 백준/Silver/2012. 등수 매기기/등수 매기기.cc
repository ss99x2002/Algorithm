#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// 예상 등수 주어질 때, 김조교를 도와 불만도 합 최소되는 프로그램 작성

int n;
int awards;
bool used[500001];
vector<int> nums;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> awards;
        nums.push_back(awards);
        used[i] = false;
    }


    sort(nums.begin(), nums.end());

    long long ans = 0;

    for (int i=0; i<nums.size(); i++){
        int rank = i+1;
        ans = ans + abs(nums[i]-rank);
    }
    cout << ans;
}