import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()
    var rope: MutableList<Int> = mutableListOf()
    for (i in 0 until N) {
        rope.add(readLine().toInt())
    }

    rope = rope.sortedByDescending { it }.toMutableList()

    var max = rope[0]
    for (i in 0 until N) {
        var kg = 0
        kg = rope[i]
        kg*=(i+1)
        if (max <= kg) max = kg
    }
    println(max)
}