import java.util.* 

class Solution {
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        var answer = intArrayOf().toMutableList()
        for (l in commands.indices){
            var i = commands[l][0]
            var j = commands[l][1]
            var k = commands[l][2]
            println("${i} , ${j} , ${k}")
            var subList = array.toMutableList().subList(i-1,j).sorted()
            println(subList.toString())
            answer.add(subList[k-1])
            println(answer.toString())
        }
        return answer.toIntArray()
    }
}