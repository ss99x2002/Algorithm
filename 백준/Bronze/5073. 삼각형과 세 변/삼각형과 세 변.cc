#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a,b,c;
int main() {
    while(1){
        vector<int> tra;
        cin >> a >> b >> c;
        if (a==0 && b==0 && c==0){
            break;
        }
        tra.push_back(a);
        tra.push_back(b);
        tra.push_back(c);
        sort(tra.begin(),tra.end());
        if (tra[2] >= tra[0] + tra[1]){
            cout << "Invalid" << "\n";
            continue;
        }
        if (a ==b  && b== c){
            cout << "Equilateral" << "\n";
        }
        else if (a ==b || b== c || a==c){
            cout << "Isosceles" << "\n";
        }
        else {
            cout << "Scalene" << "\n";
        }

    }
}

