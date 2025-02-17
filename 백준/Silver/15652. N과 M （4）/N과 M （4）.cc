#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int num[10];
int visited[10];

void checkBackTracking(int start,int cnt){
    if (cnt == m) {
        for (int i=0; i<m; i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=start; i<=n; i++){
        num[cnt] = i;
        checkBackTracking(i,cnt+1);
    }
}


int main() {
    cin >> n >> m;
    checkBackTracking(1,0);
}