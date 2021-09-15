import Foundation

private typealias KeyScore = [String: Int]
private typealias Result = (name: String, score: Int)

/**
    - Parameters:
        - table: 직업군 언어 점수를 정리한 문자열 배열
        - languages: 개발자가 사용하는 언어를 담은 문자열 배열
        - preference: 언어 선호도를 담은 정수 배열
    - NOTE:
        - table의 길이 = 5
        - 1 ≤ languages의 길이 ≤ 9
        - preference의 길이 = languages의 길이
        - 총합이 같은 직업군이 여러 개일 경우, 이름이 사전 순으로 가장 빠른 직업군을 return
*/
func solution(_ table:[String],
              _ languages:[String],
              _ preference:[Int]) -> String {

    var result: [Result] = Array.init()
    var value: [String: KeyScore] = Dictionary.init()
    
    for item in table {
        
        var score: Int = table.count
        
        let keys = item.split(separator: " ").map { String($0) }
        let areaKey = keys.first ?? String.init()
        value[areaKey] = Dictionary.init()
        
        for index in keys.indices where keys.startIndex != index {
            let language = keys[index]
            value[areaKey]?.updateValue(score, forKey: language)
            score -= 1
        }
    }
    
    for item in value {
        var totalScore = Int.zero
        for index in languages.indices {
            let lang = languages[index]
            let score = preference[index]
            
            totalScore += score * (item.value[lang] ?? Int.zero)
        }
        
        let element = Result(item.key, totalScore)
        result.append(element)
    }
    
    result.sort {
        if $0.score > $1.score { return true }
        else if $0.score == $1.score { return $0.name < $1.name }
        else { return false }
    }
    
    // MARK: -  개발자가 사용하는 언어의 언어 선호도 x 직업군 언어 점수의 총합이 가장 높은 직업군을 return 하도록 solution 함수를 완성해주세요.
    return result[Int.zero].name
}
