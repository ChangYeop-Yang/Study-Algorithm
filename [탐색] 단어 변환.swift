import Foundation

func difference(left: String, right: String) -> Int {
    
    var result: Int = Int.zero
    
    // MARK: - 각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
    for index in left.indices where left[index] != right[index] { result += 1 }
    
    return result
}

func findMinimumChangeLetter(answer: inout Int,
                             visit: inout [String: Bool],
                             word: [String],
                             count: Int, index: String,
                             begin: String, target: String) {
    
    if begin.elementsEqual(target) {
        answer = min(answer, count)
        return
    }
    
    for item in word {
        let differenceWord: Int = difference(left: begin, right: item)
        
        if visit[item] == false && differenceWord == 1 {
            visit[index] = true
            findMinimumChangeLetter(answer: &answer, visit: &visit, word: word,
                                    count: count + 1, index: item,
                                    begin: item, target: target)
        }
    }
}

/**
    1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
    2. words에 있는 단어로만 변환할 수 있습니다.
*/
func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    
    var result: Int = Int.max
    
    // MARK: - 각 단어는 알파벳 소문자로만 이루어져 있습니다.
    guard words.contains(target) else { return Int.zero }
    
    var visit: [String: Bool] = [:]
    var firstIndex: String = String.init()
    
    words.forEach { item in
        visit[item] = false
        
        if difference(left: item, right: begin) == 1 { firstIndex = item }
    }
    
    findMinimumChangeLetter(answer: &result, visit: &visit, word: words,
                            count: Int.zero, index: firstIndex,
                            begin: begin, target: target)
    
    // MARK: - begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾습니다.
    return result
}
