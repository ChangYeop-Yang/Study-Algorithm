import Foundation

internal typealias Location = (x: Int, y: Int)

internal var previous = Int.zero
internal var materix: [[Int]] = []

internal enum RotateType {
    case right, down, left, top
}

/**
    - NOTE:
        - x1 행 y1 열부터 x2 행 y2 열까지의 영역에 해당하는 직사각형에서 테두리에 있는 숫자들을 한 칸씩 시계방향으로 회전합니다.
        - 모든 회전은 순서대로 이루어집니다.
*/
func solution(_ rows: Int, _ columns: Int, _ queries: [[Int]]) -> [Int] {
    
    var result: [Int] = .init()
    
    materix = Array(repeating: Array(repeating: Int.zero, count: columns), count: rows)
    
    // 입력받은 행렬의 크기에 대해서 숫자를 채워넣습니다.
    var count = Int.zero
    for outline in materix.indices {
        materix[outline].indices.forEach {
            count = count + 1
            materix[outline][$0] = count
        }
    }

    for query in queries {
        var minValue = Int.max
        let first = Location(query[0] - 1, query[1] - 1)
        let second = Location(query[2] - 1, query[3] - 1)
        
        rotate(startIndex: first, end: second.y, value: +1, type: .right, minValue: &minValue)
        rotate(startIndex: Location(first.x, second.y), end: second.x, value: +1, type: .down, minValue: &minValue)
        rotate(startIndex: second, end: first.y + 1, value: -1, type: .left, minValue: &minValue)
        rotate(startIndex: Location(second.x, first.y), end: first.x + 1, value: -1, type: .top, minValue: &minValue)
        previous = Int.zero
        
        result.append(minValue)
    }
    
    // MARK: 회전에 의해 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 담아 return
    return result
}

func rotate(startIndex: Location, end: Int, value: Int, type: RotateType, minValue: inout Int) {
    
    var origin = previous
    
    switch type {
    case .right:
        for index in startIndex.y..<end {
            let moveItem = origin > Int.zero ? origin : materix[startIndex.x][index]
            origin = materix[startIndex.x][index + value]
            materix[startIndex.x][index + value] = moveItem
            minValue = min(minValue, moveItem)
        }
        previous = origin
    case .down:
        for index in startIndex.x..<end {
            let moveItem = origin
            origin = materix[index + value][startIndex.y]
            materix[index + value][startIndex.y] = moveItem
            minValue = min(minValue, moveItem)
        }
        previous = origin
    case .left:
        for index in stride(from: startIndex.y, through: end, by: value) {
            let moveItem = origin
            origin = materix[startIndex.x][index + value]
            materix[startIndex.x][index + value] = moveItem
            minValue = min(minValue, moveItem)
        }
        previous = origin
    case .top:
        for index in stride(from: startIndex.x, through: end, by: value) {
            let moveItem = origin
            origin = materix[index + value][startIndex.y]
            materix[index + value][startIndex.y] = moveItem
            minValue = min(minValue, moveItem)
        }
        previous = origin
    }
}
