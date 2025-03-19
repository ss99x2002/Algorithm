#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long n,c,input;

bool comp(pair<long long,pair<long long,long long>> a, pair<long long,pair<long long,long long>> b){
    if (a.second.second == b.second.second){
        return a.second.first < b.second.first;
    }
    return a.second.second > b.second.second;
}

unordered_map<int,pair<int,int>> maps;
// map 특성, key는 바뀔 수 없음 -> key를 고유숫자,
// 뒤에 pair <첨 발생 index, 빈도 수> 저장
int main(){
    cin >> n >> c;
    // n만큼 문자열 가짐, 문자 내 가질 수 있는 숫자는 c이내
    // unordered_map을 활용
    for (int i=0; i<n; i++){
        cin >> input;
        if (maps.find(input) == maps.end()){
            maps.insert({input, {i,1}});
        }
        else {
         maps.find(input)->second.second = maps.find(input)->second.second+1;
        }
    }
    vector<pair<int,pair<int,int>>> mapVector;
    for (auto i = maps.begin(); i!=maps.end(); i++){
        mapVector.push_back({i->first, {i->second.first, i->second.second}});
    }
    sort(mapVector.begin(), mapVector.end(), comp);
    for (auto i= mapVector.begin(); i!= mapVector.end(); i++){
        for (long long j=0; j<i->second.second; j++){
            cout << i->first << " ";
        }
    }
}