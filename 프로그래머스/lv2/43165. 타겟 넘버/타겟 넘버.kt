import java.util.*

class Solution {
    fun solution(numbers: IntArray, target: Int): Int {
        val queue:Queue<Pair<Int,Int>> = LinkedList()
        var answer = 0
        
        queue.offer(Pair(numbers[0],0))
        queue.offer(Pair(-numbers[0],0))
        
        while(queue.isNotEmpty()){
            var cur = queue.peek()
            queue.poll()
            if (cur.second == numbers.size-1) {
                if (cur.first==target){
                    answer ++
                }
                continue
            }
            queue.offer(Pair((cur.first+numbers[cur.second+1]),cur.second+1))
            queue.offer(Pair((cur.first-numbers[cur.second+1]),cur.second+1))     
        }
        return answer
    }
}