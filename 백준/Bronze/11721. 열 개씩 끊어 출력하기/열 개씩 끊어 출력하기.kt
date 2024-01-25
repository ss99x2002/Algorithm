import java.io.BufferedReader
import java.io.InputStreamReader

fun main()=with(BufferedReader(InputStreamReader(System.`in`))){
    var input = readLine().toString()
    
    for (i in input.indices){
        if ((i+1)%10 == 0) {
            println(input[i])
        }
        else{
            print(input[i])
        }
    }
}