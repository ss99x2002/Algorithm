import java.util.*

class Solution {
    fun solution(genres: Array<String>, plays: IntArray): IntArray {

        var songList =
            HashMap<String, MutableList<Pair<Int, Int>>>() // 장르 key, plays 횟수랑 index를 pair로 하는 원소 MutableList 가 value

        genres.forEachIndexed { index, it ->
            if (songList.containsKey(it)) {
                songList[it]!!.add(Pair(index, plays[index]))
            } else {
                songList.set(it, mutableListOf(Pair(index, plays[index])))
            }
        }

        println(songList.toList().toString())

        songList.forEach { // 각 장르 별
            it.value.sortByDescending {
                it.second //재생횟수 높은 순으로 내림차순 정렬
            }
        }

        println(songList.toList().toString())

        var list = songList.toList().sortedByDescending {
            if (it.second.size >= 2) {
                var sum : Int = 0 
                for (i in it.second.indices){
                    sum += it.second[i].second 
                }
                sum
            } else {
                it.second[0].second
            }
        }.toMap()


        println(list.toList().toString())

        var answer: MutableList<Int> = mutableListOf()
        list.forEach {
            if (it.value.size < 2) {
                answer.add(it.value[0].first)
            } else {
                for (i in 0 until 2) {
                    answer.add(it.value[i].first)
                }
            }
        }
        return answer.toIntArray()
    }
}
