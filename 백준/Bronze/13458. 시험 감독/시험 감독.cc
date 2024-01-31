#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,A,B, C;
    long long ans = 0;
    vector <int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        v.push_back(A);
    }
    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        if (B >= v[i]) {
            ans++;
        }
        else {
            v[i] = v[i] - B; // 주감독 +1 
            ans++;
            if (v[i] > 0) {
                if (v[i] % C == 0) {
                    ans = ans + (v[i] / C);
                }
                else {
                    ans = ans + (v[i] / C) + 1;
                }
            }
        }
    }
    cout << ans;
}