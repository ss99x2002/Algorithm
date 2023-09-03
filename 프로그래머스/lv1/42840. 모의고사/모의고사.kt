class Solution {
    fun solution(answers: IntArray): IntArray {
        var answer : MutableList<Int> = mutableListOf()
        var case1 = intArrayOf(1, 2, 3, 4, 5)
        var case2 = intArrayOf(2, 1, 2, 3, 2, 4, 2, 5)
        var case3 = intArrayOf(3, 3, 1, 1, 2, 2, 4, 4, 5, 5)
        var cnt = mutableListOf(0, 0, 0)

        for (i in answers.indices){
            if (answers[i] == case1[i%5]) {
                cnt[0]+=1
            }
            if (answers[i] == case2[i%8]){
                cnt[1]+=1
            }
            if (answers[i]==case3[i%10]){
                cnt[2]+=1
            }
        }

        var max = 0
        cnt.forEach{
            if (it > max) {
                max = it
            }
        }
        
        for (i in cnt.indices){
            if (cnt[i]==max) {
                answer.add(i+1)
            }
        }
        return answer.toIntArray()
    }
}
