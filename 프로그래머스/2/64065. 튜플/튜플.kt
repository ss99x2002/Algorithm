class Solution {
    fun solution(s: String): IntArray {
        var answer = intArrayOf()
        
        var ms : MutableSet<Int> = mutableSetOf()
        
        var modifiedString = s.substring(1, s.length-1)
        modifiedString = modifiedString.replace("},", "/").replace("{", "").replace("}","")
        
        var list = modifiedString.split("/")
        var resultList = list.map{group -> group.split(",").map {it.toInt()}}
    
     resultList = resultList.sortedBy { it.size }
     
     
     resultList.forEach { group ->
         group.forEach{ it ->
             ms.add(it)
         }
     }
     
        
        return ms.toIntArray()
    }
}