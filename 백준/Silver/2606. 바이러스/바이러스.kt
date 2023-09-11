import java.util.*
import java.io.*

var cnt = 0

fun main()=with(BufferedReader(InputStreamReader(System.`in`))){
    val computer = readLine().toInt()
    val edge = readLine().toInt()

    var visit = BooleanArray(computer+1)

    var graph = LinkedHashMap<Int,LinkedList<Int>>()

    for (i in 0 .. computer){
        graph.set(i,LinkedList())
    }

    for (i in 0 until edge){
        val input = readLine().split(" ")
        graph.get(input[0].toInt())!!.add(input[1].toInt())
        graph.get(input[1].toInt())!!.add(input[0].toInt())
    }
    dfs(graph, visit, 1)
    println(cnt-1)
}

fun dfs(graph:LinkedHashMap<Int,LinkedList<Int>>,visit:BooleanArray,start:Int){
    cnt ++
    visit[start]= true
    for (i in graph[start]!!.indices){
        if (visit[graph[start]!![i]]) continue
        dfs(graph,visit,graph[start]!![i])
    }
}


