class Solution {
    fun solution(citations: IntArray): Int {
        var max = 0
        citations.forEach {
            if (max <= it) {
                max = it
            }
        }
        var notCnt = 0
        var cnt = 0
        var answer = 0
        for (i in 0..max) {
            notCnt = 0
            cnt = 0
            citations.forEach {
                if (it <= i) {
                    notCnt++
                }
                if (it >= i) {
                    cnt++
                }
            }
            if (i in notCnt..cnt) {
                if (answer < i ) {
                    answer = i
                }
            }
        }
        return answer
    }
}
