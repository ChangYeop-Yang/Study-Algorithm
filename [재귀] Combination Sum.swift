class Solution {
    
func sumCombination(target: Int, candidate: [Int], temp: inout [Int], result: inout Set<[Int]>) {
    
    let total: Int = temp.reduce(Int.zero, +)
    
    // 찾고자 하는 값이 목표의 값보다 더 큰 경우에는 함수를 종료합니다.
    if target < total { return }
    
    // 찾고자 하는 값이 목표의 값과 동일한 경우에는 현재 값을 저장한 뒤 함수를 종료합니다.
    if target == total {
        result.insert(temp.sorted())
        return
    }
    
    for value in candidate {
        temp.append(value)
        sumCombination(target: target, candidate: candidate, temp: &temp, result: &result)
        temp.removeLast()
    }
}

// MARK: - The same number may be chosen from candidates an unlimited number of times.
func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
    
    var temp: Array<Int> = []
    var result: Set<[Int]> = []
    
    // MARK: - return a list of all unique combinations of candidates where the chosen numbers sum to target.
    sumCombination(target: target, candidate: candidates, temp: &temp, result: &result)
    
    // MARK: - You may return the combinations in any order.
    return Array(result)
}
}
