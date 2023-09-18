import java.util.*


class Solution {
    fun solution(clothes: Array<Array<String>>): Int {
        var clothesCategory = 0
        var category = LinkedHashMap<String, LinkedList<String>>()
        clothes.forEach {
            if (!category.containsKey(it[1])) {
                category.set(it[1], LinkedList())
                clothesCategory ++
            }
        }

        for (i in clothes.indices) {
            category.forEach {
                if (it.key == clothes[i][1]) {
                    category[it.key]!!.add(clothes[i][0])
                }
            }
        }

        var answer = 1
        category.forEach{
            answer = answer * (it.value.size+1)
        }
        return answer-1
    }
}