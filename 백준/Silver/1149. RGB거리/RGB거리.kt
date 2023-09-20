import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt() //집의 수
    val colors = Array(3){IntArray(N)} // 집의 수 만큼 빨강,초록,파랑의 비용값 넣는 리스트
    // colors를 담을 때 유의해야 함.
    for (i in 0 until N){
        var input = readLine().split(" ")
        for (j in input.indices){
            colors[j][i] = input[j].toInt() //j번째 color로 i번째 집을 색칠할 때 비용
        }
    }

    val d = Array(N+1){IntArray(3) {0} } //i번째 집을 j번째 color로 색칠할 때 누적 최소비용.
    d[1][0] = colors[0][0] //1번째 집을 0번째 color로 색칠 할때 최소비용
    d[1][1] = colors[1][0]
    d[1][2] = colors[2][0]

    for (i in 2 .. N){
        d[i][0] = min(d[i-1][1],d[i-1][2]) + colors[0][i-1]
        d[i][1] = min(d[i-1][0],d[i-1][2]) + colors[1][i-1]
        d[i][2] = min(d[i-1][0],d[i-1][1]) + colors[2][i-1]
    }
    var min = d[N][0]

    for (i in 0 .. 2){
        if (d[N][i] < min){
            min = d[N][i]
        }
    }
    println(min)
}