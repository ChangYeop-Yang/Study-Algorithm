import Foundation

// MARK: 문자열에서 같은 알파벳이 2개 붙어 있는 짝을 찾습니다. 그다음, 그 둘을 제거한 뒤, 앞뒤로 문자열을 이어 붙입니다.
func solution(_ s: String) -> Int{
    
    var result: [String.Element] = []
    for letter in s {
        let priviousIndex = result.index(before: result.endIndex)
        
        if priviousIndex >= Int.zero && letter == result[priviousIndex] {
            result.removeLast()
            continue
        }
        
        result.append(letter)
    }
    
    return result.isEmpty ? 1 : Int.zero
}
