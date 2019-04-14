import Foundation

func searchTarget(number: [Int], depth: Int, target: Int, value: Int, answer: inout Int) {
    
    // MARK: - 사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.
    if depth >= number.count {
        if target == value { answer = answer + 1 }
        return
    }
    
    // MARK: - 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다.
    searchTarget(number: number, depth: depth + 1, target: target, value: value + number[depth], answer: &answer)
    searchTarget(number: number, depth: depth + 1, target: target, value: value - number[depth], answer: &answer)
}

func solution(_ numbers:[Int], _ target:Int) -> Int {
    
    var answer = 0
    searchTarget(number: numbers, depth: 0, target: target, value: 0, answer: &answer)
    
    return answer
}
