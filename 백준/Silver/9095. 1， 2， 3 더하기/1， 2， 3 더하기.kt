import java.io.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val T = readLine().toInt()
    for (i in 0 until T) {
        val input = readLine().toInt()
        var d = Array(11){0}
        d[0] = 0
        d[1] = 1
        d[2] = 2
        d[3] = 4
        for (i in 4 .. input){
            d[i] = d[i-1]+d[i-2]+d[i-3]
        }
        println(d[input])
    }
}