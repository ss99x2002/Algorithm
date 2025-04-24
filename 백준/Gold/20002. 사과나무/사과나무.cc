#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

// n*n 과수원에, 사과나무 1*1 간격 심어져있음.
// 농부 형곤 과수원 내 k*k 크기 정사각형 모양으로 수확 가능
// 사과를 통해 얻은 이익과, 노동비를 더한 총 이익을 2차원 배열로 정리
// 형곤이가 최대 총 이익을 얻을 수 있는 최댓값은?

int n;
int board[301][301];
int prefixSum[301][301];

int answer = INT16_MIN;


int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> board[i][j];
            prefixSum[i][j] = board[i][j] + prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1];
        }
    }

    for (int k=1; k<=n; k++){
        for (int i=k; i<=n; i++){
            for (int j=k; j<=n; j++){
                int sum = prefixSum[i][j] - prefixSum[i-k][j] - prefixSum[i][j-k] + prefixSum[i-k][j-k];
               answer  = max(answer, sum);
            }
        }
    }

    cout << answer;
}