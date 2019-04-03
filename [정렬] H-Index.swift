import Foundation

// MARK: - https://en.wikipedia.org/wiki/H-index
func solution(_ citations:[Int]) -> Int {
    
    let length = citations.count
    
    // MARK: - First we order the values of f from the largest to the lowest value. (DESC - 오름차순)
    let paper = citations.sorted { $0 > $1 }
        
    // MARK: - we look for the last position in which f is greater than or equal to the position (we call h this position).
    var hIndex: Int = 0
    for index in 0..<length where paper[index] >= index + 1 { hIndex = hIndex + 1 }
    
    return hIndex
}
