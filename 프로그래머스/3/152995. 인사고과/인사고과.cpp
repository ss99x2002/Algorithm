#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>
using namespace std;

vector<int> availIncen;
vector<pair<int,int>> wins;
int scoreFind[200001];
vector<vector<int>> scores;
vector<bool> dominated;

// 기존과 동일한 비교 함수
bool compWins(const pair<int,int>& a, const pair<int,int>& b){
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

// 이제 O(1)로 바뀐 findIncen
bool findIncen(int x, int y, int idx){
    return !dominated[idx];
}

void calWins(){
    wins.clear();
    fill(scoreFind, scoreFind+200001, 0);
    for (int i : availIncen) {
        int s = scores[i][0] + scores[i][1];
        scoreFind[s]++;
        wins.emplace_back(s, scoreFind[s]);
    }
}

int solution(vector<vector<int>> scoress) {
    scores = move(scoress);
    int n = scores.size();
    int wanhoSum = scores[0][0] + scores[0][1];

    // 1) dominated 배열 전처리
    dominated.assign(n, false);
    vector<tuple<int,int,int>> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        v.emplace_back(scores[i][0], scores[i][1], i);
    }
    sort(v.begin(), v.end(), [](auto &A, auto &B){
        if (get<0>(A) != get<0>(B))
            return get<0>(A) > get<0>(B);
        return get<1>(A) < get<1>(B);
    });
    int maxY = -1;
    for (int i = 0; i < n; ) {
        int x = get<0>(v[i]);
        int j = i;
        while (j < n && get<0>(v[j]) == x) j++;
        for (int k = i; k < j; k++) {
            int y   = get<1>(v[k]);
            int idx = get<2>(v[k]);
            if (y < maxY) dominated[idx] = true;
        }
        for (int k = i; k < j; k++) {
            maxY = max(maxY, get<1>(v[k]));
        }
        i = j;
    }
    if (dominated[0]) return -1;

    // 2) 기존대로 availIncen 채우기
    availIncen.clear();
    for (int i = 0; i < n; i++) {
        int sum = scores[i][0] + scores[i][1];
        if (sum >= wanhoSum && findIncen(scores[i][0], scores[i][1], i)) {
            availIncen.push_back(i);
        }
        else if (i == 0) {
            return -1;
        }
    }

    // 3) 나머지 로직
    calWins();
    sort(wins.begin(), wins.end(), compWins);

    int total = wins.size();
    vector<int> chart(total);
    chart[0] = 1;
    int start = 1, wanhoIdx = 0;
    for (int i = 1; i < total; i++) {
        if (wins[i].first == wins[i-1].first) {
            chart[i] = start;
        } else {
            start += wins[i-1].second;
            chart[i] = start;
        }
        if (wins[i].first == wanhoSum) {
            wanhoIdx = i;
            break;
        }
    }
    return chart[wanhoIdx];
}

