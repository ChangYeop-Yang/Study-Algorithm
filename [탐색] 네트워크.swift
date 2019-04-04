import Foundation

let CONNECTED = 1

func findConnected(visited: inout [Bool], map: [[Int]], index: Int, size: Int) {
    
    visited[index] = true
    
    for ii in 0..<size {
        let there = map[index][ii]
        if visited[ii] == false && there == CONNECTED {
            findConnected(visited: &visited, map: map, index: ii, size: size)
        }
    }
}

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    
    var visited: [Bool] = Array(repeating: false, count: n)
    
    var answer = 0
    for index in 0..<n where visited[index] == false {
        answer = answer + 1
        findConnected(visited: &visited, map: computers, index: index, size: n)
    }
    
    return answer
}
