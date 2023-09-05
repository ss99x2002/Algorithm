import java.lang.Math.*

class Solution {
    fun solution(numbers: String): Int {
        var numberList: MutableList<Int> = mutableListOf()
        numbers.forEach {
            numberList.add(it.toString().toInt())
        }

        numberList.sortByDescending {
            it
        }

        var number = ""
        numberList.forEach {
            number += it.toString()
        }
        var answer = 0
        for (i in 1..number.toInt()) {
            if (isPrime(i)) {
                var numString = i.toString()
                var numListCopy = numberList.toMutableList()
                var idx = 0
                for (j in numString.indices) {
                    for (k in numListCopy.indices) {
                        if (numString[j].toString().toInt() == numListCopy[k]) {
                            numListCopy[k] = -1
                            idx++
                            break
                        }
                    }
                }
                if (idx == numString.length) {
                    answer++
                }
            }

        }
        return answer
    }

    fun isPrime(number: Int): Boolean {
        if (number == 0 || number == 1) return false
            for (i in 2..sqrt(number.toDouble()).toInt()) {
                if (number % i == 0) return false
            }
        return true
    }
}