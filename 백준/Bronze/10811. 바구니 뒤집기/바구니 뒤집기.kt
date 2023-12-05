import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val input = readLine().split(" ")
    val N = input[0].toInt()
    val M = input[1].toInt()

    var list : MutableList<Int> = mutableListOf()

    for (i in 1 .. N) {
        list.add(i)
    }

    for (i in 0 until M){
        val line = readLine().split(" ")
        list.subList(line[0].toInt()-1,line[1].toInt()).reverse()
    }

    list.forEach{
        print("${it} ")
    }
}