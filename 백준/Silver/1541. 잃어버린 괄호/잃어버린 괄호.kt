
import java.io.BufferedReader
import java.io.InputStreamReader

fun main()=with(BufferedReader(InputStreamReader(System.`in`))){

    val input = readLine()!!
    var total = 0
    var num = 0
    var isSum = true // status 
    for (c in input) {
        if (c == '-' || c == '+') {
            total += if (isSum) num else -num
            if (isSum) isSum = c == '+'
            num = 0 
        }
        else {
            num = num * 10 + (c - '0')
        }
    }
    total += if (isSum) num else -num
    print(total)
}