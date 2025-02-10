#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
int nArr[500001];

int M;
int mArr[500001];

int binarySearch(int target) {
    int st = 0;
    int en = N - 1;
    while (st <= en) {
        int mid = (st + en) / 2;
        if (nArr[mid] < target) {
            st = mid+1;
        } else if (nArr[mid] > target) {
            en = mid-1;
        } else {
            return 1;
        }
    }
    return 0;
}


int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> nArr[i];
    }
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> mArr[i];
    }

    sort(nArr, nArr+N);

    for (int i=0; i<M; i++){
        cout << binarySearch(mArr[i]) << " ";
    }
    return 0;
}
