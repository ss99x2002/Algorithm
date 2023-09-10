class Solution {
    fun solution(n: Int, computers: Array<IntArray>): Int {
        val graph = Array(n) { IntArray(n) }
        val visit = BooleanArray(n)

        var i = 0
        computers.forEach {
            graph[i] = it
            i++
        }

        var answer = 0

        for (i in 0 until n) {
            if (!visit[i]) {
                dfs(i, visit, graph)
                answer++
            }
        }
        return answer
    }
}

fun dfs(start: Int, visit: BooleanArray, graph: Array<IntArray>) {
    visit[start] = true
    for (i in graph[start].indices) {
        if (i == start || graph[start][i] != 1) continue
        if (visit[i]) continue
        dfs(i, visit, graph)
    }
}
