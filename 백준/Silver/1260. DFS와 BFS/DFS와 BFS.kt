import java.util.*
import java.io.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val input = readLine().split(" ")
    val N = input[0].toInt()
    val M = input[1].toInt()
    val start = input[2].toInt()
    val queue: Queue<Int> = LinkedList()
    val stack = Stack<Int>()
    val visit = BooleanArray(N + 1)

    var graph = LinkedHashMap<Int, LinkedList<Int>>()

    for (i in 0..N) {
        graph.set(i, LinkedList())
    }

    for (i in 0 until M) {
        var str = readLine().split(" ")
        graph.get(str[0].toInt())!!.add(str[1].toInt())
        graph.get(str[1].toInt())!!.add(str[0].toInt())
    }

    graph.forEach {
        it.value.sort()
    }

    dfs(stack, visit, graph,start)

    println()
    initVisit(visit)

    queue.offer(start)
    visit[start] = true
    bfs(queue, visit, graph)

}

fun bfs(queue: Queue<Int>, visit: BooleanArray, graph: LinkedHashMap<Int, LinkedList<Int>>) {
    while (queue.isNotEmpty()) {
        val cur = queue.peek()
        print("$cur ")
        queue.poll()
        for (i in graph[cur]!!.indices) {
            var vertex = graph[cur]!![i]
            if (visit[vertex]) continue
            queue.offer(vertex)
            visit[vertex] = true
        }
    }
}

fun dfs(stack: Stack<Int>, visit: BooleanArray, graph: LinkedHashMap<Int, LinkedList<Int>>,start:Int) {
    stack.push(start)
    while (stack.isNotEmpty()) {
        val cur = stack.peek()
        stack.pop()
        if (visit[cur]) continue
        visit[cur] = true
        print("$cur ")
        for (i in graph[cur]!!.indices) {
            val vertex = graph[cur]!![graph[cur]!!.size - 1 - i]
            if (visit[vertex]) continue
            stack.push(vertex)
        }
    }
}

fun initVisit(visit: BooleanArray) {
    for (i in visit.indices) {
        visit[i] = false
    }
}