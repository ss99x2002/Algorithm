class Solution {
    fun solution(sizes: Array<IntArray>): Int {
        var sizeList:MutableList<List<Int>> = mutableListOf()
        for (i in sizes.indices){
            sizeList.add(sizes[i].sortedDescending())
        }
        var maxH=0
        var maxW=0
        sizeList.forEach{
            if (it[0]>maxH){
                maxH = it[0]
            }
            if (it[1]>maxW) {
                maxW = it[1]
            }
        }
        
        var answer = maxH * maxW
        return answer
    }
}