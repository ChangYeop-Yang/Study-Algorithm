import Foundation


/**
    - NOTE:
        - 1 ≤ s의 길이 ≤ 50
        - s가 "zero" 또는 "0"으로 시작하는 경우는 주어지지 않습니다.
        - return 값이 1 이상 2,000,000,000 이하의 정수가 되는 올바른 입력만 s로 주어집니다.
*/
func solution(_ s: String) -> Int {
    
    var result: String = String.init()
    
    var numbers: [String: String] = ["zero": "0", "one": "1",
                                     "two": "2", "three": "3",
                                     "four": "4", "five": "5",
                                     "six": "6", "seven": "7",
                                     "eight": "8", "nine": "9"]
    
    // 주어진 문자열이 숫자의 형태만 있는 경우
    if s.allSatisfy { $0.isNumber } { return Int(s) ?? Int.zero }
    
    var key: String = String.init()
    for letter in s {
        // 해당 문자가 숫자인 경우에는 특별한 작업없이 추가합니다.
        if letter.isNumber {
            result.append(letter)
            continue
        }
        
        key.append(letter)
        if let value = numbers[key] {
            key.removeAll()
            result.append(value)
        }
    }
    
    return Int(result) ?? Int.zero
}
