import java.util.*
import java.io.*

fun main()=with(BufferedReader(InputStreamReader(System.`in`))){
    // i와 j의 첫 시작을 0으로 시작해서 크기를 N 배열로 설정함.
    val N = readLine().toInt()
    val graph = LinkedHashMap<Int,LinkedList<Int>>()// 입력에서 0과 1로 주어지기 때문에, 따로 0으로 초기화 할 필요가 없다.
    val visit = IntArray(N)

    for (i in 0 until N){
        graph.set(i,LinkedList())
    }

    for (i in 0 until N){
        var str = readLine().split(" ")
        for (j in 0 until N){
            if (str[j].toInt() == 1){
                graph[i]!!.add(j)
            }
        }
    } // graph 에 입력 값 담기

    for (i in 0 until N){
        dfs(visit,graph,i)
        for (j in 0 until N){
            print("${visit[j]} ")
        }
        println()
        initVisit(visit)
    }
}

fun dfs(visit:IntArray, graph:LinkedHashMap<Int,LinkedList<Int>>,start:Int) {
   for (i in graph[start]!!.indices){
       if (visit[graph[start]!![i]]==1) continue
       visit[graph[start]!![i]] = 1
       dfs(visit,graph,graph[start]!![i])
   }
}

fun initVisit (visit:IntArray) {
   for (i in visit.indices){
       visit[i] = 0
   }
}

