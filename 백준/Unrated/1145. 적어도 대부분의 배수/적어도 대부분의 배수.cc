#include <iostream>
using namespace std;
int arr[5];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    int str = 1, cnt = 0;
    while (1) {
        cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (str % arr[i] == 0) {
                cnt++;
            }
            if (cnt == 3) {
                cout << str;
                return 0;
            }
        }
        str++;
    }
}