
import java.io.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt() //출입 기록 수
    val people = HashMap<String, String>()
    val answer : MutableList<String> = mutableListOf()

    for (i in 0 until n) {
        val str = readLine().split(" ")
        val name = str[0]
        val state = str[1]
        if (people.containsKey(name)) {
            people.replace(name, state)
        } else {
            people.set(name, state)
        }
    }

    people.forEach {
        if (it.value == "enter"){
            answer.add(it.key)
        }
    }

    answer.sortByDescending { it }
    answer.forEach{
        println(it)
    }
}