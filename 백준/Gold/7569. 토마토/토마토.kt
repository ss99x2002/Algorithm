import java.io.*
import java.util.*

var notTomatoCnt = 0
fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val input = readLine().split(" ")
    val M = input[0].toInt()
    val N = input[1].toInt()
    val H = input[2].toInt()
    var allTomatoFlag = 0

    val board = Array(H) { Array(N) { IntArray(M) } } //3차원 토마토가 담긴 상자
    var queue: Queue<Pair<Pair<Int, Int>, Int>> = LinkedList() //3차원 좌표 담는 queue x,y,z 순

    for (i in 0 until H) {
        for (j in 0 until N) {
            var num = readLine().split(" ")
            for (k in 0 until M) {
                board[i][j][k] = num[k].toInt()
                if (num[k].toInt() == 1) {
                    queue.offer(Pair(Pair(j, k), i)
                    ) //순차적으로 도는게 아니라 토마토는 각 구간에서 각자 익을 수 있기 때문에, queue에 바로 삽입.
                }  else if (num[k].toInt() == 0) {
                    allTomatoFlag = 1 //안익은 토마토가 하나라도 있음을 알 수 있는 조건.
                    notTomatoCnt++
                }
            }
        }
    }

    if (allTomatoFlag == 0) { //모든 토마토가 익은 상황.
        println(0)
        return
    }

    var day = 0
    var exceptionCnt = 0

    while (queue.isNotEmpty() && notTomatoCnt > 0) {
        for (i in queue.size-1 downTo 0 ){
            bfs(board, notTomatoCnt, queue, M, N, H)
        }
        day ++
    }

    if (notTomatoCnt == 0){
        println(day)
    }
    else {
        println(-1)
    }
}

fun bfs(
    board: Array<Array<IntArray>>,
    cnt: Int,
    queue: Queue<Pair<Pair<Int, Int>, Int>>,
    M: Int,
    N: Int,
    H: Int
) {
    val cur = queue.peek()
    val dx = arrayOf(1, 0, -1, 0, 0, 0)
    val dy = arrayOf(0, 1, 0, -1, 0, 0)
    val dz = arrayOf(0, 0, 0, 0, 1, -1)
    queue.poll()
    for (i in 0 until 6) {
        var nx = cur.first.first + dx[i]
        var ny = cur.first.second + dy[i]
        var nz = cur.second + dz[i]

        if (nx >= N || nx < 0 || ny >= M || ny < 0 || nz >= H || nz < 0 || board[nz][nx][ny] != 0) continue
        board[nz][nx][ny] = 1
        notTomatoCnt--
        queue.offer(Pair(Pair(nx, ny), nz))
    }
}