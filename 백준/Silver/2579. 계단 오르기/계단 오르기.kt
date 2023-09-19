
import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val cnt = readLine().toInt()
    val list = Array(cnt + 1) { 0 }
    for (i in 1..cnt) {
        list[i] = readLine().toInt() //계단 리스트에 넣기
    }

    val d = Array(301) { IntArray(3) { 0 } }
    // d[i][j]는 현재까지 j개의 계단 연속해서 밟은 i단계 계단의 합 최댓값.
    if (cnt == 1){
        println(list[1])
        return
    }
    d[1][1] = list[1]
    d[2][1] = list[2]
    d[2][2] = list[1]+list[2]

    for (i in 3..cnt) {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + list[i]
        d[i][2] = d[i-1][1]+list[i]
    }
    println(max(d[cnt][1], d[cnt][2]))
}