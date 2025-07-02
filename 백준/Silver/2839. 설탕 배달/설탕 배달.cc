#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    while(n>=0) {
        if (n%5==0){
            ans = ans + (n/5);
            cout << ans;
            return 0;
        }
        n=n-3;
        ans++;
    }
    cout << -1 << "\n";
}