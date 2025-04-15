#include <string>
#include <vector>

using namespace std;
// 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return
// 중앙은 노란색, 테두리는 갈색 카페트
// 가로 = 세로 or 가로 > 세로
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int by_plus = (brown-4)/2;
    for (int i=1; i<by_plus; i++){
        int tmp_x = i;
        int tmp_y = by_plus - i;
        if (tmp_x * tmp_y == yellow) {
            answer.push_back(tmp_y+2);
            answer.push_back(tmp_x+2);
            break;
        }
    }
    return answer;
    
    
    
    
    return answer;
}