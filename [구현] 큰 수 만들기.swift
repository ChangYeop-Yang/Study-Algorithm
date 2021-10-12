import Foundation

/**
    - NOTE:
        - number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
        - k는 1 이상 number의 자릿수 미만인 자연수입니다.
*/
func solution(_ number: String, _ k: Int) -> String {
    
    var removeRemainder = k
    var result: String = String.init()
    
    // 해당 문제를 구현함에 있어 주의할 점은 해당 숫자의 위치를 움직여서 큰 수를 만드는 방식이 아니다.
    for letter in number {
        
        if result.isEmpty {
            result.append(letter)
            continue
        }
        
        while !result.isEmpty && result.last! < letter && removeRemainder > Int.zero {
            removeRemainder -= 1
            result.removeLast()
        }
        
        result.append(letter)
    }
    
    // MARK: - number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 반환하세요.
    if removeRemainder > Int.zero {
        let endIndex = result.index(result.startIndex, offsetBy: number.count - removeRemainder)
        return String(result[result.startIndex..<endIndex])
    }
        
    return result
}
