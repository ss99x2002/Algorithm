import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()
    var A: MutableList<Int> = mutableListOf()
    var B: MutableList<Int> = mutableListOf()

    val inputA = readLine().split(" ")
    for (i in 0 until N) {
        A.add(inputA[i].toInt())
    }

    val inputB = readLine().split(" ")
    for (i in 0 until N) {
        B.add(inputB[i].toInt())
    }

    A = A.sortedBy { it }.toMutableList()
    B = B.sortedByDescending { it }.toMutableList()

    var ans = 0
    for (i in 0 until N){
        ans += A[i]*B[i]
    }
    println(ans)
}