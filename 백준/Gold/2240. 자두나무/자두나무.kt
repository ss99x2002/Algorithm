import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max
import java.math.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val input = readLine().split(" ")
    val T = input[0].toInt()
    val W = input[1].toInt()

    val tree = Array(T+1) { 0 } //자두가 떨어지는 트리 위치 array
    var d = Array(3) { Array(T + 1) { Array(W + 1) { 0 } } }

    for (i in 1..T) {
        tree[i] = readLine().toInt()
    }

    if (tree[1] == 1) { //첫나무 1
        d[1][1][0] = 1
        d[2][1][1] = 0
    } else { //첫나무 2
        d[1][1][0] = 0
        d[2][1][1] = 1
    } //초기값 세팅

    for (i in 2..T) {
        if (tree[i] == 1) { //현재 자두나무 1
            d[1][i][0] = d[1][i-1][0] + 1 //한번도 안 움직인 경우
            d[2][i][0] = d[2][i-1][0]
            for (j in 1..W) { //w는 이동한 횟수
                d[1][i][j] = max(d[1][i-1][j],d[2][i-1][j-1])+1
                d[2][i][j] = max(d[1][i-1][j-1],d[2][i-1][j])
            }
        } else { // 현재 자두나무 2
            d[1][i][0] = d[1][i-1][0] //한번도 안 움직인 경우
            d[2][i][0] = d[2][i-1][0] + 1
            for (j in 1..W) { //w는 이동한 횟수
                d[1][i][j] = max(d[1][i-1][j],d[2][i-1][j-1])
                d[2][i][j] = max(d[1][i-1][j-1],d[2][i-1][j]) +1
            }
        }
    } //점화식 배열안에 값 다 넣음

    var ans = -1
    for (i in 0 .. W){
        ans = max(d[tree[T]][T][i],ans)
    }

    println(ans)
}