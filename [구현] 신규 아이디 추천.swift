import Foundation

let except: Set<String.Element> = ["-", "_", ".", "0", "1",
                                   "2", "3", "4", "5", "6",
                                   "7", "8", "9", "q", "w",
                                   "e", "r", "t", "y", "u",
                                   "i", "o", "p", "a", "s",
                                   "d", "f", "g", "h", "j",
                                   "k", "l", "z", "x", "c",
                                   "v", "b", "n", "m"]

/**
    - NOTE:
        - 아이디의 길이는 3자 이상 15자 이하여야 합니다.
        - 아이디는 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.) 문자만 사용할 수 있습니다.
        - 단, 마침표(.)는 처음과 끝에 사용할 수 없으며 또한 연속으로 사용할 수 없습니다.
*/
func solution(_ new_id: String) -> String {
    
    var result: String = String.init()
    
    // 1단계: new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    result = new_id.lowercased()
    
    // 2단계: new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    result = result.filter { except.contains($0) }
    
    // 3단계: new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    let regex = try! NSRegularExpression(pattern: "[.]{2,}", options: .caseInsensitive)
    
    while true {
        let range = NSRange(location: Int.zero, length: result.count)
        guard let firstMatch = regex.firstMatch(in: result, range: range) else { break }
        
        for _ in Int.zero..<firstMatch.range.length - 1 {
            let startIndex = result.index(result.startIndex, offsetBy: firstMatch.range.location)
            result.remove(at: startIndex)
        }
    }
    
    // 4단계: new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if result.first == "." { result.removeFirst() }
    if result.last == "." { result.removeLast() }

    // 5단계: new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if result.isEmpty { result.append("a") }

    // 6단계: new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다. 만약, 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    while result.count >= 16 { result.removeLast() }
    if result.last == "." { result.removeLast() }
    
    // 7단계: new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    while result.count < 3 { result.append(result.last!) }
    
    return result
}
