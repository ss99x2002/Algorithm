#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 소문자로만 이루어짐
// 아스키 a : 97

int used[27];
int n;
int ans =0;
string inputs;

void initUsed(){
    for (int i=0; i<27; i++) {
        used[i]= 0;
    }
}

bool isGroup(string in){
    for (int i=0; i<in.size()-1; i++){
        if (in[i] == in[i+1]) {
            used[in[i]-'a']++;
        }
        else {
            if (used[in[i+1] - 'a'] != 0){
                return false;
            }
            used[in[i]-'a']++;
            continue;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> inputs;
        if(isGroup(inputs)) {
            ans ++;
        }
        initUsed();
    }

    cout << ans << "\n";
    return 0;
}