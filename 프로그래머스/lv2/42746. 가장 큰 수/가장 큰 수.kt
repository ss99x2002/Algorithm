import java.util.*
class Solution {
    object SortByNum : Comparator <String>{
        override fun compare(o1: String?, o2: String?): Int {
            return (o2+o1).toInt().compareTo((o1+o2).toInt())
        }
    }
    fun solution(numbers: IntArray): String {
       var numberString :MutableList<String> = mutableListOf()
        numbers.forEach{
            numberString.add(it.toString())
        }
        var answer  = numberString.sortedWith(SortByNum)
        if (answer[0] == "0") {
            return "0"
        }
        return answer.joinToString("")
    }
}
