#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long n;
long long input;

// n은 최대 10^6 -----> n(lonN) 시간 복잡도의 알고리즘 사용.
// 입력 정수 최대 10^12
// 10 ^ 6 * 10^12 = 10 ^18 최대 복잡도 발생 -> 1억 걍 넘음

// 시간제한 1초 -> 보통 1억번 연산 가능.

// 문제 해결 과정
// 1. 숫자를 담고
// 2. 다음 숫자를 뒤집고
// 3. 그 숫자들을 오름차순으로 출력해야 한다.

// 정렬 n(logN) ->

vector<long long> nums;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> input;
        string ele = "";
        int tmp;
        while (input >= 1) {
            tmp = input % 10;
            ele = ele.append(to_string(tmp));
            input = input / 10;
        }
        nums.push_back(stoll(ele));
    }

    sort(nums.begin(), nums.end());

    for (long long i = 0; i < nums.size(); i++) {
        cout << nums[i] << "\n";
    }
}