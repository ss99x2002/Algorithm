#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A;
int aArr[500001];

int B;
int bArr[500001];

int answerCnt = 0;

// A에는 속하면서 B에는 속하지 않는 원소를 출력
int binarySearch(int target) {
    int st = 0;
    int en = B - 1;

    while (st <= en) {
        int mid = (st + en) / 2;
        if (bArr[mid] < target) {
            st = mid + 1;
        } else if (bArr[mid] > target) {
            en = mid - 1;
        } else
            return -1;
    }
    return target;
}

void printAnswer(vector<int> answer, bool flag) {

    if (flag) {
        cout << answerCnt << "\n";
        sort(answer.begin(), answer.end());
        for (auto iter = answer.begin(); iter != answer.end(); iter++) {
            cout << *iter << " ";
        }
    } else {
        cout << 0;
    }


}

int main() {
    vector<int> answer;
    bool flag = false;
    cin >> A >> B;
    for (int i = 0; i < A; i++) {
        cin >> aArr[i];
    }

    for (int i = 0; i < B; i++) {
        cin >> bArr[i];
    }
      sort (bArr, bArr+B);

    for (int i = 0; i < A; i++) {
        if (binarySearch(aArr[i]) != -1) {
            answer.push_back(aArr[i]);
            answerCnt++;
            flag = true;
        }
    }

    printAnswer(answer, flag);
    return 0;
}
