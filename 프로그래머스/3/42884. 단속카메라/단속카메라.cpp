#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    // 진출 지점 기준 정렬
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });

    vector<pair<int, int>> cr; // 교집합 구간 리스트
    for (const auto& route : routes) {
        int start = route[0];
        int end = route[1];

        bool found = false;
        for (auto& zone : cr) {
            // 교집합이 존재하면 범위 업데이트
            if (zone.second >= start && zone.first <= end) {
                zone.first = max(zone.first, start);
                zone.second = min(zone.second, end);
                found = true;
                break;
            }
        }

        if (!found) {
            cr.push_back({start, end});
        }
    }

    return cr.size();
}
