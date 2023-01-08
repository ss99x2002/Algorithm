#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) {
    	string p;
    	cin >> p;
    	
    	int n;
    	cin >> n;
    
    	string numArr;
    	cin >> numArr;
    	
    	deque<int> dq;
    	string tmp = "";
    	
    	for(int i = 0; i < numArr.size(); i++) {
    		if(numArr[i] == '[') {
    			continue;
			} else if(numArr[i] >= '0' && numArr[i] <= '9') {
    			tmp += numArr[i];
			} else if(numArr[i] == ',' || numArr[i] == ']') {
				if(!tmp.empty()) {
					dq.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}
		
		bool flag = true; // 정방향 == true, 역방향 == false 
		bool isEmpty = false;
		for(int i = 0; i < p.size(); i++) {
			if(p[i] == 'R') {
				flag = !flag; // 방향 변경 
			} else {
				if(!dq.empty()) {
					if(flag) {
						dq.pop_front();
					} else {
						dq.pop_back();
					}
				} else {
					isEmpty = true;
					cout << "error\n";
					break;
				}
			}
		}
		 
		if(!isEmpty) {
			cout<<"[";
			if(flag) {
				while(!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if(!dq.empty()) cout<<",";
				}
			} else {
				while(!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if(!dq.empty()) cout<<",";
				}
			}
			cout << "]\n";
		}
	}
}