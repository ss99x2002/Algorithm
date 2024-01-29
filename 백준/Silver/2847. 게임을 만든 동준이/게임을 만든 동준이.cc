#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int score; 
    vector <int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> score;
        v.push_back(score);
    }

    int max = v.back(); //최대가 되는 max 값 
    int ans = 0;

    for (int i = N-2; i >= 0; i--) {
        if (v[i] >= max) {
            int tmp = max - 1;
            ans = v[i] - tmp + ans;
            max = tmp;
        }
        else {
            max = v[i];
        }
    }
    cout << ans << "\n";
}
