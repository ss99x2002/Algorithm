#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M,num;
    string order;
    cin >> M;
    int arr[21] = { 0 };
    for (int i = 0; i < M; i++) {
        cin >> order;
        if (order == "add") {
            cin >> num;
            arr[num] = 1;
        }
        else if (order == "remove") {
            cin >> num;
            if (arr[num]==1) {
                arr[num] = 0;
            }
        }
        else if (order == "check") {
            cin >> num;
            if (arr[num] == 1) {
                cout << 1 << "\n";
            }
            else
                cout << 0 << "\n";
        }
        else if (order == "toggle") {
            cin >> num;
            if (arr[num] == 1) {
                arr[num] = 0;
            }
            else {
                arr[num] = 1;
            }
        }
        else if (order == "all") {
            for (int i = 1; i <= 20; i++) {
                arr[i] = 1;
            }
        }
        else if (order == "empty") {
            for (int i = 1; i <= 20; i++) {
                arr[i] = 0;
            }
        }
    }
}