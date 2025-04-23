#include <iostream>
#include <algorithm>

using namespace std;


// 0과 1로만 이루어진 행렬 A와 행렬 B있음.
// 행렬 A를 B로 바꾸는데 필요한 연산 횟수 최솟값 구하는 프로그램

// 0->1, 1->0
// 어떤 3*3 크기 부분 행렬에 있는 모든 원소 뒤집는 것.

// 그리디:
// 매 순간 현재 가장 좋아보이는 선택을 했을 때, 전체 문제에서도 정답이 되는 것.
// 즉 탐욕적으로 선택해도 전체 최적해 유지가 되는 근거.

int n,m;
int a[51][51];
int b[51][51];
int answer = 0;
string s;
int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++) {
           a[i][j] = s[j] - '0';
        }
    }

    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++) {
            b[i][j] = s[j] - '0';
        }
    }

    for (int i=0; i<=n-3; i++){
        for (int j=0; j<=m-3; j++){
            if (a[i][j] != b[i][j]){
                for (int k=i; k<i+3; k++){
                    for (int l=j; l<j+3; l++){
                        a[k][l] = 1 - a[k][l];
                    }
                }
                answer ++;
            }
            else continue;
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (a[i][j] != b[i][j]){
                answer = -1;
                cout << answer;
                return 0;
            }
        }
    }

    cout << answer;
    return 0;


}