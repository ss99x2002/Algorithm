import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max
import java.math.*
import java.util.Vector

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()
    var time: MutableList<Pair<Int, Int>> = mutableListOf()
    for (i in 0 until N) {
        val input = readLine().split(" ")
        time.add(Pair(input[0].toInt(), input[1].toInt()))
    } // 각 time 다 넣기

    time = time.sortedWith(compareBy({it.second},{it.first} )).toMutableList()
    
    var ans = 1
    var firstTime = time[0]
    for (i in 1 until N){
        if (firstTime.second <= time[i].first){
            firstTime = time[i]
            ans ++
        }
    }
    println(ans)
}