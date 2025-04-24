#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;
// 지민 = 64cm 막대 가지고 있음
// x cm 막대 가지고 싶어짐.
// 원래 막대를 더 작은 막대로 잘라서, 풀 붙여서 x cm 막대 만들려고 함
// 절반을 계속 자른걸 합쳐서 x cm로 만들고 싶음.

// 갖고 있는 막대중 길이 짧은것 절반으로 자름
// 자른 막대 중 절반 버리고 남은 막대의 길이의 합이 x보다 크거나 같다면,
// 위에서 자른 막대의 절반 중 하나를 버린다.
// 남아있는 막대를 풀로 붙여서 x 만든다.

// 몇개의 막대를 풀로 붙여서 x 만들 수 있을지?

int x;
vector<int> bar;

// 비트마스팅으로 이진수 -> 1 되는 부분의 갯수 구하면 됨.
// 왜냐면 절반씩 계속 나누니까..
int main(){
    cin >> x;
    cout << bitset<32>(x).count();
}