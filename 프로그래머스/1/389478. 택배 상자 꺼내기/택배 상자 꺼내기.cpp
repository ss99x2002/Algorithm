#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1~n까지 택배상자 창고 있음
// 왼-오 번호 순서대로 택배상자 하나씩 놓기
// 가로로 w개 놓았으면 위층으로 올라가서 w개 (이때 좌우 반전)
//이렇게 n개 놓음.

//만약 8번 꺼내려면 20,17꺼낸 후 꺼낼수 있음


// 꺼내려는 상자를 포함해서 몇개 꺼내야하는지 구하기.
// n : 택배 상자 총 합
// w : 가로로 놓는 택배 수
// num : 택배 상자 번호 (꺼내려는)

#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

int solution(int n, int w, int num) {
    // 총 층(행) 수
    int h = (n + w - 1) / w;
    // 대상 상자가 놓인 행(1-베이스)
    int targetRow = (num - 1) / w + 1;
    // 대상 상자의 행 내 순서(1~w)
    int mod = (num - 1) % w + 1;
    // 지그재그 배치에 따른 실제 열 위치
    int pos = (targetRow % 2 == 0)
              ? (w - (mod - 1))
              : mod;
    // 마지막 행에 남은 상자 개수
    int rem = n % w;
    if (rem == 0) rem = w;

    int count = 0;
    // 대상 행부터 최상단 행까지
    for (int i = targetRow; i <= h; ++i) {
        if (i == targetRow) {
            // 대상 상자 자신
            count++;
        }
        else if (i < h) {
            // 완전 채워진 중간 행
            count++;
        }
        else {
            // 최상단(마지막) 행
            if (i % 2 == 1) {
                // 순방향: 1~rem 칸만 채워짐
                if (pos <= rem) count++;
            } else {
                // 역방향: w-rem+1 ~ w 칸만 채워짐
                if (pos >= w - rem + 1) count++;
            }
        }
    }
    return count;
}
