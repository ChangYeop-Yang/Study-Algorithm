import Foundation

func findCharCount(target: String, compare: String, length: Int) -> Int {
    
    var answer = Int.zero
    
    for index in (Int.zero..<length) {
                
        let firstIndex = String.Index(utf16Offset: index, in: target)
        let secondIndex = String.Index(utf16Offset: index, in: compare)
        
        guard target[firstIndex] == compare[secondIndex] else { break }
        
        answer = answer + 1
    }
    
    return answer
}

func solution(_ words: [String]) -> Int {
    
    var answer: [Int] = Array(repeating: Int.min, count: words.count)
    
    // 효과가 얼마나 좋을지 알고 싶은 라이언은 학습된 단어들을 찾을 때 몇 글자를 입력하는지 찾습니다.
    let sortedWords = words.sorted(by: <)
    
    let count = sortedWords.count
    for index in (Int.zero..<count - 1) {
        let previous = sortedWords[index]
        let next = sortedWords[index + 1]
        
        let length = min(previous.count, next.count)
        let matchCount = findCharCount(target: previous, compare: next, length: length)
        
        // 두 문자열의 가장 짧은 길이와 문자열 일치 갯수가 동일한 경우는 해당 문자열이 다음 문자열에 대해서 접두사를 포함하고 있다.
        if length == matchCount {
            answer[index] = max(answer[index], matchCount)
        } else {
            answer[index] = max(answer[index], matchCount + 1)
        }
        
        answer[index + 1] = max(answer[index + 1], matchCount + 1)
    }
    
    // 문자열이 입력으로 주어지면 학습을 시킨 후, 학습된 단어들을 순서대로 찾을 때 몇 개의 문자를 입력 수 구합니다.
    return answer.reduce(Int.zero, +)
}
