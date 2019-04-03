import Foundation

func solution(_ numbers:[Int]) -> String {
    
    var numbersString = numbers.compactMap({ String($0) })
    numbersString.sort { $0 + $1 > $1 + $0 }
    
    var answer = String()
    for item in numbersString {
        answer.append(contentsOf: item)
    }
    
    return answer.first! == "0" ? "0" : answer
}
