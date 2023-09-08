import java.io.*
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val input = readLine().split(" ")
    var m = input[0].toInt()
    var n = input[1].toInt()
    var k = input[2].toInt()

    var board = Array(m) { IntArray(n) }
    var visited = Array(m) { IntArray(n) { -1 } } // -1로 전체 초기화
    var queue: Queue<Pair<Int, Int>> = LinkedList()

    for (i in 0 until k) {
        var str = readLine().split(" ")
        while (true) {
            var start = Pair(str[1].toInt(), str[0].toInt())
            var end = Pair(str[3].toInt() - 1, str[2].toInt() - 1)
            for (i in start.first..end.first) {
                for (j in start.second..end.second) {
                    board[i][j] = 1
                    visited[i][j] = 1
                }
            }
            break
        }
    } // 좌표 바탕으로 1,0 bfs board 만들기
    var cnt = 0
    var width = 0
    var widthList : MutableList<Int> = mutableListOf()
    for (i in 0 until m){
        for (j in 0 until n){
            width = 0
            if (board[i][j]==0 && visited[i][j]==-1){
                cnt ++
                visited[i][j]=0
                queue.offer(Pair(i,j))
                while(queue.isNotEmpty()){
                    width ++
                    bfs(queue,board,visited,m,n)
                }
                widthList.add(width)
            }
        }
    }

    println(cnt)
    widthList.sorted().forEach{
        print("$it ")
    }
}

fun bfs(queue: Queue<Pair<Int,Int>>, board:Array<IntArray>,visited:Array<IntArray>,m:Int,n:Int){
    val dx = arrayOf(1,0,-1,-0)
    val dy = arrayOf(0,1,0,-1)
    val cur = queue.peek()
    queue.poll()
    for (i in 0 until 4){
        var nx = cur.first + dx[i]
        var ny = cur.second + dy[i]
        if (nx >= m || nx < 0 || ny >= n || ny < 0) continue
        if (visited[nx][ny] == 1 || visited[nx][ny]==0 || board[nx][ny]==1) continue
        visited[nx][ny]=0
        queue.offer(Pair(nx,ny))
    }
}