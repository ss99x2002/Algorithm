#include <iostream>
using namespace std;

int n;
int input;
int num[2000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> input;
        num[input+1000000]++;
    }

    for (int i=0; i<2000001; i++){
        if (num[i] != 0) {
            for (int j=0; j<num[i]; j++){
                cout << i-1000000 << "\n";
            }
        }
    }
}