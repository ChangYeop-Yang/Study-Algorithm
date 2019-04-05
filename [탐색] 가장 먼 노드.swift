import Foundation

let CONNECTED: Int = 1
let UNCONNCTED: Int = 0

public struct Queue<T> {
    fileprivate var array = [T]()
    
    public var front: T? { return array.first }
    public var count: Int { return array.count }
    public var isEmpty: Bool { return array.isEmpty }
    public mutating func enqueue(_ element: T) { array.append(element) }
    public mutating func dequeue() -> T? { return isEmpty ? nil : array.removeFirst() }
}

func findShortDistance(size: Int, index: Int, visited: inout [Int], board: [[Int]]) {
    
    visited[index] = CONNECTED
    
    var queue = Queue<Int>()
    queue.enqueue(index)
    
    while !queue.isEmpty {
        
        guard let here = queue.front else { break }
        queue.dequeue()
        
        for index in board[here] where visited[index] < CONNECTED {
            queue.enqueue(index)
            visited[index] = visited[here] + 1
        }
     }
}


func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    
    // MARK: - 인접행렬 (Adjacency Matrix)
    var board = [[Int]](repeating: Array<Int>(), count: n)
    var visited = Array<Int>(repeating: UNCONNCTED, count: n)
    
    for node in edge {
        let index: (first: Int, second: Int) = (node.first! - 1, node.last! - 1)
        // MARK: - U간선은 양방향이며 총 1개 이상 50,000개 이하의 간선이 있습니다. vertex 배열 각 행 [a, b]는 a번 노드와 b번 노드 사이에 간선이 있다는 의미입니다.
        board[index.first].append(index.second)
        board[index.second].append(index.first)
    }
    
    // MARK: - 1번 노드에서 가장 멀리 떨어진 노드의 갯수를 구하려고 합니다.
    findShortDistance(size: n, index: 0, visited: &visited, board: board)
    
    // MARK: - 1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 return 하도록 solution 함수를 작성해주세요.
    visited.sort()
    return visited.filter { visited.last! == $0 }.count
}
