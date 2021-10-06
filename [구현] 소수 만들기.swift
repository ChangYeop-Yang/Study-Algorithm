import Foundation

var isPrime: [Bool] = Array.init()

func isPrimeNumber(value: Int) {
    // 만일 주어진 수가 1보다 작거나 같을 경우에는 소수가 아니다.
    if value <= 1 { return }
    
    isPrime = Array(repeating: true, count: value + 1)
    isPrime[Int.zero] = false
    isPrime[1] = false
    
    var index: Int = 2
    while (index * index) <= value {
        for number in stride(from: index * index, to: value, by: +index) where isPrime[index] {
            isPrime[number] = false
        }
        index += 1
    }
}

func permutation(target: Array<Int>, orderSet: Set<Int>, result: Int, index: Int, anwser: inout Set<Set<Int>>) {
    
    if index > 3 { return }
    
    if index == 3 && isPrime[result] {
        anwser.insert(orderSet)
        return
    }
    
    for (position, number) in target.enumerated() {
        var copyArray = target
        copyArray.remove(at: position)
        
        var copyOrderSet = orderSet
        copyOrderSet.insert(number)
        
        permutation(target: copyArray, orderSet: copyOrderSet, result: result + number, index: index + 1, anwser: &anwser)
    }
}

/**
    - NOTE:
        - nums에 들어있는 숫자의 개수는 3개 이상 50개 이하입니다.
        - nums의 각 원소는 1 이상 1,000 이하의 자연수이며, 중복된 숫자가 들어있지 않습니다.
*/
func solution(_ nums:[Int]) -> Int {
    
    var answer: Set<Set<Int>> = Set.init()
    
    isPrimeNumber(value: 99999)
    
    // MARK: 주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구합니다.
    permutation(target: nums, orderSet: Set.init(), result: Int.zero, index: Int.zero, anwser: &answer)
    
    // MARK: 숫자들 중 서로 다른 3개를 골라 더했을 때 소수가 되는 경우의 개수를 구합니다.
    return answer.count
}
