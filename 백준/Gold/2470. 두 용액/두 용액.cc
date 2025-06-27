#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// 산성 용액과 알칼리성 용액 값 있을 때
// 서로 다른 두 용액 혼합해서 특성값 0에 가까운 용액 2개 찾기.

int n,num;
vector<long long> nums;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    long long ansL = 0, ansR = 0;

    int left = 0;
    int right = nums.size()-1;
    long long bestAbs = LLONG_MAX;

    while(left < right) {
        long long sum = nums[left] + nums[right];
        if (llabs(sum) < bestAbs) {
            bestAbs = llabs(sum);
            ansL = nums[left];
            ansR = nums[right];
        }

        if (sum > 0) {
            right--;
        }
        else if (sum < 0) {
            left++;
        }
        else {
            break;
        }
    }
    cout << ansL << " " << ansR << "\n";
}