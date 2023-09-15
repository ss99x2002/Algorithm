import java.io.*
import java.util.*
import java.math.*
import kotlin.math.min

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    var n = readLine().toInt()
    var d = Array(1000005) { 0 }
    d[0] = 0
    d[1] = 0

    for (i in 2..n) {
        d[i] = d[i - 1] + 1
        if (i % 2 == 0) {
            d[i] = min(d[i / 2] + 1, d[i])
        }
        if (i % 3 == 0) {
            d[i] = min(d[i / 3] + 1, d[i])
        }
    }
    println(d[n])

    while (true ){
        print("$n ")
        if (n==1){
            return
        }
        if (d[n] == d[n-1]+1) {
            n=n-1
        }
        else if (n%2==0 && d[n] == d[n/2]+1){
            n=n/2
        }
        else if (n%3==0 && d[n] == d[n/3]+1){
            n=n/3
        }
    }

}



