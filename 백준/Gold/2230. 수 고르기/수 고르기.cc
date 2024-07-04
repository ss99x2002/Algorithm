#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M;
int A[100001];
int minV = 0x7fffffff;


int main(){
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    sort (A,A+N);
    int en = 0;
    for (int st = 0; st < N; st++){
        while(en < N && A[en]-A[st] < M){
            en ++;
        }
         if (en == N) break;
         minV = min(minV, A[en]-A[st]);
    }
    cout << minV << endl;
}