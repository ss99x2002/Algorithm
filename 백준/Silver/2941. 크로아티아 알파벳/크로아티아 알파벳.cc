#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
string input;

int main() {

    cin >> input;
    int i = 0;
    int ans = 0;
    while (i < input.size()) {
        if (input.substr(i, 2) == "c=") {
            ans++;
            i = i + 2;
        } else if (input.substr(i, 2) == "c-") {
            ans++;
            i = i + 2;
        } else if (input.substr(i, 2) == "d-") {
            ans++;
            i = i + 2;
        } else if (input.substr(i, 2) == "lj") {
            ans++;
            i = i + 2;
        } else if (input.substr(i, 2) == "nj") {
            ans++;
            i = i + 2;
        } else if (input.substr(i, 2) == "s=") {
            ans++;
            i = i + 2;
        } else if (input.substr(i, 2) == "z=") {
            ans++;
            i = i + 2;
        } else if (input.substr(i, 3) == "dz=") {
            ans++;
            i = i + 3;
        }
        else {
            i++;
            ans ++;
            continue;
        }
    }

    cout << ans << "\n";
    return 0;
}