import Foundation

func distance(_ target: String, index: inout String.Index) -> Int {
    
    // ▶ - 커서를 오른쪽으로 이동
    var rightIndex: String.Index = index
    
    while target.endIndex != rightIndex && target[rightIndex] == "A" {
        target.formIndex(after: &rightIndex)
    }
    
    // ◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
    var leftIndex: String.Index = index
    var leftDistance: Int = Int.zero
    
    if index == target.startIndex {
        leftDistance += 1
        leftIndex = target.index(before: target.endIndex)
    }
    
    while target[leftIndex] == "A" {
        leftDistance += 1
        
        if leftIndex == target.startIndex {
            leftIndex = target.index(before: target.endIndex)
            continue
        }
        
        target.formIndex(before: &leftIndex)
    }
    
    let rightDistance = abs(target.distance(from: index, to: rightIndex))
    
    if rightIndex == target.endIndex || rightDistance > leftDistance {
        index = leftIndex
        return leftDistance
    } else {
        index = rightIndex
        return rightDistance
    }
}

/**
    ▲ - 다음 알파벳
    ▼ - 이전 알파벳 `(A에서 아래쪽으로 이동하면 Z로)`
    ◀ - 커서를 왼쪽으로 이동 `(첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)`
    ▶ - 커서를 오른쪽으로 이동
*/
func solution(_ name: String) -> Int {
    // MARK: - 맨 처음엔 A로만 이루어져 있습니다.
    let alphabat: [UInt8] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".compactMap { $0.asciiValue }
    
    var replace = name
    let target = String(repeating: "A", count: name.count)
    var result = Int.zero
    
    var index = target.startIndex
    while target != replace {
        // MARK: - 커서 이동의 최솟값을 찾습니다.
        result += distance(replace, index: &index)
        
        // MARK: - 알파벳의 최솟값을 찾습니다.
        if replace[index] != "A" {
            let firstIndex = alphabat.firstIndex(of: replace[index].asciiValue!)!
            let leftValue = alphabat.distance(from: alphabat.endIndex, to: firstIndex)
            let rightValue = alphabat.distance(from: alphabat.startIndex, to: firstIndex)
            
            replace.replaceSubrange(index...index, with: "A")
            result += min(abs(leftValue), rightValue)
        }
    }
    
    // MARK: - 조이스틱 조작 횟수의 최솟값
    return result
}
