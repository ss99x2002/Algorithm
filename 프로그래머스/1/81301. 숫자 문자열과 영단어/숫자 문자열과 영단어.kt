enum class Number(val num : Int){
    zero(0),
    one(1),
    two(2),
    three(3),
    four(4),
    five(5),
    six(6),
    seven(7),
    eight(8),
    nine(9)
}


class Solution {
    fun solution(s: String): Int {
        var answer: Int = 0
        var answerString = s
        
        Number.values().forEach{ string ->
                answerString = answerString.replace(string.name.toString(), string.num.toString())
        }
        
        println(answerString)
        
        answer = answerString.toInt()
        
        return answer
    }
}