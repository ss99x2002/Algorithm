import java.io.*
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val queue: Queue<Pair<Int, Int>> = LinkedList()
    var homeCntList: MutableList<Int> = mutableListOf()
    var cnt = 0
    var home = 0

    var n = readLine().toInt()

    val board = Array(n) { IntArray(n) }
    val visited = Array(n) { BooleanArray(n) }

    for (i in 0 until n) {
        val str = readLine()
        for (j in 0 until n) {
            board[i][j] = (str[j] + "").toInt()
        }
    }

    for (i in 0 until n) {
        for (j in 0 until n) {
            if (!visited[i][j] && board[i][j] == 1) {
                cnt++
                home = 0
                visited[i][j] = true
                queue.offer(Pair(i, j))
                while (queue.isNotEmpty()) {
                    bfs(queue, visited, board, n)
                    home++
                }
                homeCntList.add(home)
            }
        }
    }

    println(cnt)
    homeCntList.sorted().forEach{
        println(it)
    }
}

fun bfs(
    queue: Queue<Pair<Int, Int>>,
    visited: Array<BooleanArray>,
    board: Array<IntArray>,
    n: Int
) {
    val dx = arrayOf(1, 0, -1, 0)
    val dy = arrayOf(0, 1, 0, -1)
    var cur = queue.peek()
    queue.poll()
    for (i in 0 until 4) {
        val nx = cur.first + dx[i]
        val ny = cur.second + dy[i]
        if (nx >= n || nx < 0 || ny >= n || ny < 0) continue
        if (visited[nx][ny] || board[nx][ny] != 1) continue
        visited[nx][ny] = true
        queue.offer(Pair(nx, ny))
    }
}