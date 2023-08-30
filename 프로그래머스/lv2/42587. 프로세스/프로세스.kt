import java.util.LinkedList
import java.util.Queue

class Solution {
var queue: Queue<Int> = LinkedList<Int>()
fun solution(priorities: IntArray, location: Int) : Int {
   var sortedPr =  priorities.sortedDescending()
    sortedPr.forEach{
        queue.add(it)
    }
    var answer = 0
    while (!queue.isEmpty()) {
        for (i in priorities.indices) {
            if (priorities[i] == queue.peek()) {
                queue.poll()
                answer++
                if (i == location) {
                    return answer
                }
            }
        }
    }
    return answer
}

}