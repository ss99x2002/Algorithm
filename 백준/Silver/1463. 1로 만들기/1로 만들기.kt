import java.io.*
import kotlin.math.min

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    var d  = Array(1000006){0}
    d[1] = 0
    for (i in 2 .. n) {
        d[i] = d[i-1]+1
        if (i%2 == 0) d[i] = min(d[i/2]+1,d[i])
        if (i%3 == 0) d[i] = min(d[i/3]+1,d[i])
    }
    println(d[n])

}



