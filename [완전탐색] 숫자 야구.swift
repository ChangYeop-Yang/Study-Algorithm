import Foundation

typealias Compare = (score: [Character], strike: Int, ball: Int)

func checkDuplicate(target: [Character]) -> Bool {
    for char in target where char == "0" { return true }
    return (target[0] == target[1]) || (target[0] == target[2]) || (target[1] == target[2])
}

func collectScore(strike: Int, ball: Int, target: [Character], answer: [Character]) -> Bool {
    
    let length = answer.count
    var score: (strike: Int, ball: Int) = (0, 0)
    
    for outline in 0..<length {
        // MARK: - 숫자와 위치가 모두 맞을 때는 스트라이크
        if answer[outline] == target[outline] { score.strike = score.strike + 1; continue }
        
        // MARK: - 숫자는 맞지만, 위치가 틀렸을 때는 볼
        for inline in 0..<length where outline != inline && answer[outline] == target[inline] { score.ball = score.ball + 1; break }
    }
    return score.strike == strike && score.ball == ball
}

func solution(_ baseball: [[Int]]) -> Int {
    
    var answer = 0
    
    // MARK: - 각자 서로 다른 1~9까지 3자리 임의의 숫자를 정한 뒤 서로에게 3자리의 숫자를 불러서 결과를 확인합니다.
    let range: (start: Int, end: Int) = (100, 999)
    for exception in range.start...range.end {
        let bucket = Array(String(exception))
        if checkDuplicate(target: bucket) { continue }
        
        var value = 0
        for target in baseball {
            let compare = Compare(Array(String(target[0])), target[1], target[2])
            
            if collectScore(strike: compare.strike, ball: compare.ball, target: compare.score, answer: bucket) {
                value = value + 1
            }
        }
        
        // MARK: - 결과를 토대로 상대가 정한 숫자를 예상한 뒤 맞힌 경우
        if value == baseball.count { answer = answer + 1 }
    }
    
    return answer
}
