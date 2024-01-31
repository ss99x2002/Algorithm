#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int P, L, V; //연속하는 p일중 l일 사용가능 v짜리 휴가 
    int a = 0;
    int ans = 0;
    while (true) {
        cin >> L >> P >> V;
        if (L == 0 &&  P == 0 && V == 0) {
            break;
        }
        a++;
        int day;
        if (V % P == 0) {
            day = V / P;
            ans = L * day;
        }
        else {
            day = V / P;
            ans = L * day;
            if (V % P > L) {
                ans = ans + L;
            }
            else {
                ans = ans + (V % P);
            }
        }
        cout << "Case " << a << ": " << ans << "\n";
    }
}
