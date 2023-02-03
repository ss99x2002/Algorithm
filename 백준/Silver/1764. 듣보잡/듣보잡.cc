#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    string nl;
    map <string, int> ans;
    vector<string> vec;
    cin >> N >> M;
    for (int i = 0; i < N+M; i++) {
        cin >> nl;
        ans[nl]++;
        if (ans[nl] > 1) {
            vec.push_back(nl);
        }
    }
    sort(vec.begin(), vec.end());
    
    cout << vec.size() << "\n";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
    }

}