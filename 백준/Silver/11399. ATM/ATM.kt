
import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()
    val input = readLine().split(" ")
    var time: MutableList<Int> = mutableListOf()
    for (i in 0 until N) {
        time.add(input[i].toInt())
    }

    time = time.sortedBy { it }.toMutableList()

    var total = 0

    for (i in time.indices){
        for (j in 0 .. i){
            total += time[j]
        }
    }
    println(total)
}