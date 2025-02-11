#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
// n=노트북 세로, m=노트북 가로, k=스티커 갯수

int r, c;
// 스티커 r,c
// 0=스티커 없는 칸, 1=스티커 있는 칸

int note[41][41];
int sticker[11][11];

void rotate() {
    int tmps[11][11];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmps[i][j] = sticker[i][j];
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            sticker[i][j] = tmps[r - 1 - j][i];
        }
    }
    swap(r, c);
}

bool checkSticker(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (note[x + i][y + j] == 1 && sticker[i][j] == 1) {
                return false;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 1) {
                note[x + i][y + j] = 1;
            }
        }
    }
    return true;
} // 2차원 배열 전달 시 두번째 차원의 크기 반드시 지정해야 함.

int main() {

    int cnt = 0;
    cin >> n >> m >> k;

    while (k--) {
        cin >> r >> c;
        for (int j = 0; j < r; j++) {
            for (int z = 0; z < c; z++) {
                cin >> sticker[j][z];
            }
        }

        bool isPaste = false;
        for (int rota = 0; rota < 4; rota++) {
            for (int j = 0; j <= n - r; j++) {
                if (isPaste) break;
                for (int z = 0; z <= m - c; z++) {
                    if (checkSticker(j, z)) {
                        isPaste = true;
                        break;
                    }
                }
            }
            if (isPaste) break;
            rotate();
        }
        // 노트북에 스티커를 붙일 수 있는지 check 후 스티커를 붙이는 함수 호출.
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (note[i][j] == 1) {
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}