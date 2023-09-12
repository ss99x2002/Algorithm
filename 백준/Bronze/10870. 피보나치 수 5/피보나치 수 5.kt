import java.io.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    println(fibonacci(n))
}

fun fibonacci(n: Int): Int {
    return when (n) {
        1 -> 1
        0 -> 0
        else -> {
            fibonacci(n - 1) + fibonacci(n - 2)
        }
    }
}

