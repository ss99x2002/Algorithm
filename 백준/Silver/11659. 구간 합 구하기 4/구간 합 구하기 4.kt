import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val input = readLine().split(" ")
    val N = input[0].toInt()
    val M = input[1].toInt()
    var d = Array(N + 1) { 0 }
    var answerList: MutableList<Int> = mutableListOf()

    val num = readLine().split(" ")
    for (i in 1 until N + 1) {
        d[i] = num[i - 1].toInt() + d[i - 1]
    }

    for (i in 0 until M) {
        val str = readLine().split(" ")
        val start = str[0].toInt()
        val end = str[1].toInt()

        if (start == 1) {
            answerList.add(d[end])
        } else if (start == end) {
            answerList.add(d[end] - d[end - 1])
        } else {
            answerList.add(d[end] - d[start - 1])
        }
    }

    answerList.forEach {
        println(it)
    }
}