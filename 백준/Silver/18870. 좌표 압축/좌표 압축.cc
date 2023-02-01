#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vec;
    int N, X;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X;
        vec.push_back(X);
    }
    vector<int> uni(vec);
    sort(uni.begin(), uni.end());

    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for (int i = 0; i < N; i++) {
        cout << lower_bound(uni.begin(), uni.end(), vec[i]) - uni.begin() << " ";
    }
}