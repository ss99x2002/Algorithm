#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> pieces, string t) {
    int N = t.size();
    const int INF = N + 5;
    vector<int> dp(N+1, INF);
    dp[0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (auto &w : pieces) {
            int L = w.size();
            if (i >= L && t.compare(i - L, L, w) == 0) {
                dp[i] = min(dp[i], dp[i - L] + 1);
            }
        }
    }
    return (dp[N] >= INF ? -1 : dp[N]);
}
