import java.io.*
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    var input = readLine().split(" ")
    var queue: Queue<Int> = LinkedList()
    var N = input[0].toInt()
    var M = input[1].toInt()
    var visit = BooleanArray(N+1)
    var graph = LinkedHashMap<Int, LinkedList<Int>>()
    for (i in 0..N) {
        graph.set(i, LinkedList())
    }

    for (i in 1..M) {
        var str = readLine().split(" ")
        graph.get(str[0].toInt())?.add(str[1].toInt())
        graph.get(str[1].toInt())?.add(str[0].toInt())
    }

    var cnt = 0
    for (i in 1..N) {
        if (visit[i] == false) {
            queue.offer(i)
            visit[i] = true
            bfs(queue, graph, visit)
            cnt++
        }
    }
    println(cnt)
}

fun bfs(queue: Queue<Int>, graph: LinkedHashMap<Int, LinkedList<Int>>, visit: BooleanArray) {
    while (queue.isNotEmpty()) {
        var cur = queue.peek()
        queue.poll()
        for (i in graph[cur]!!.indices) {
            var vertex = graph[cur]!!.get(i)
            if (visit[vertex]) continue
            queue.offer(vertex)
            visit[vertex] = true
        }
    }
}