class Solution {
    fun solution(numbers: String): Int {
        var answer = 0
        val numSet = HashSet<Int>()
       
        makeNumberSet("", numbers, numSet)
        
        while(numSet.iterator().hasNext()){
          
            val num = numSet.iterator().next()
            numSet.remove(num)
            
            if(isPrime(num)) answer++
        }
        
        return answer
    }
    
    fun makeNumberSet(prefix:String, numbers:String, numSet:HashSet<Int>){
       
        if(prefix != "") numSet.add(prefix.toInt())
        for(i in numbers.indices){
           
            makeNumberSet("$prefix${numbers[i]}", numbers.substring(0, i) + numbers.substring(i+1), numSet)
        }
    }
    
    fun isPrime(num:Int):Boolean{
       
        if(num <= 1) return false

        return (2..Math.sqrt(num.toDouble()).toInt()).none{ num % it == 0 }
    }
}