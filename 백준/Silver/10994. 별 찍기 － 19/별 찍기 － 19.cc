#include <iostream>
using namespace std;

char map[500][500];

void rec(int n, int x, int y) {

    if (n == 1) {
        map[x][y] = '*';
        return;
    }

    int len = 4 * (n - 1) + 1;

    for (int j = y; j < y + len; j++) {
        map[x][j] = '*';
        map[x + len - 1][j] = '*';
    }

    for (int i = x; i < x + len; i++) {
        map[i][y] = '*';
        map[i][y + len - 1] = '*';
    }

    rec(n - 1, x + 2, y + 2);


}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < 4 * (n - 1) + 1; i++) {
        for (int j = 0; j < 4 * (n - 1) + 1; j++) {
            map[i][j] = ' ';
        }
    }

    rec(n, 0, 0);

    for (int i = 0; i < 4 * (n - 1) + 1; i++) {
        for (int j = 0; j < 4 * (n - 1) + 1; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }

}