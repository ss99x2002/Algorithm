#include <iostream>
#include <algorithm>
using namespace std;

//합이 S이상 되는 것 중에서 가장 짧은 것의 길이 구하는 프로그램 작성. 
// 최소 길이 출력, 만약 합을 만들 수가 없다면 0 출력 

int N,S;
int A[100001];
int minV = 0x7fffffff;
int total;

int main(){
    cin >> N >> S;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    total = A[0];
    int en = 0;
    for (int st=0; st<N; st++){
        while(en<N && total < S) {
            en++;
            if (en!=N) total = total + A[en];
        }
        if (en==N) break;
        minV = min (minV,en-st+1);
        total = total - A[st];
    }
    if (minV == 0x7fffffff) minV =0; 
    cout << minV;
}